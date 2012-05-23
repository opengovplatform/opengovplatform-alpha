#!/bin/bash                                                  |_|
# THIS SCRIPT BELONGS TO NIC. Any unauthorized use,
# reproduction, modification, or disclosure of this script is strictly 
# prohibited.

PGREP="/usr/bin/pgrep"
MySQL="mysqld"
START="/sbin/service mysqld start"

etchost="/etc/hosts"
etchost_bk="/etc/hosts.org"
Mycnf="/etc/my.cnf"
Mycnfpromote="/etc/my_promote.cnf"
Mycnfold="/etc/my_org.cnf"


cat /etc/hosts > /home/ipdetails.txt

#FE Servers

export demodatacms=`cat /home/ipdetails.txt | awk '{print $2 " " $1}' | grep -w ^demodatacms |  awk '{print $2}'`
export demodatafe1=`cat /home/ipdetails.txt | awk '{print $2 " " $1}' | grep -w ^demodatafe1 |  awk '{print $2}'`
export demodatafe2=`cat /home/ipdetails.txt | awk '{print $2 " " $1}' | grep -w ^demodatafe2 |  awk '{print $2}'`
export lb1=`cat /home/ipdetails.txt | awk '{print $2 " " $1}' | grep -w ^lb1 |  awk '{print $2}'`


#DB servers

export master=`cat /home/ipdetails.txt | awk '{print $2 " " $1}' | grep -w ^master |  awk '{print $2}'`
export slave=`cat /home/ipdetails.txt | awk '{print $2 " " $1}' | grep -w ^slave |  awk '{print $2}'`


#check the status of mysql service

counter=0
attempt="a b c d e"
for var in $attempt
do
if [ `ssh $master $PGREP ${MySQL} | wc -l` -ne 2 ] # if mysql service is not running
then
counter=`expr $counter + 1`
sleep 5
fi
done

if [ $counter -eq 5 ] # mysql service is really not running, checked 5 times
then
echo "mysql service is really not running, checked 5 times"
ssh $master $START
/usr/sbin/sendmail -oi -t << EOF
From: Production_Master
To: nic-ogpl@nic.in,opengovplatform@gmail.com
Subject: Alert, Mysql master service on $master was down

FYI, Master MySQL services were not accessible. Took necessary action and started service. please check replication on slaves.
Please check log files for more details.
EOF
fi

# Numerous attempts have found that MySQL is not able to start on this machine (mysql master).
# We will now proceed to make necessary changes in /etc	hosts files

echo "Check availability of mysql service on $master"

counter=0
attempt="a b c d e"
for var in $attempt
do
if [ `ssh $master $PGREP ${MySQL} | wc -l` -ne 2 ] # if mysql service is not running
then
counter=`expr $counter + 1`
sleep 5
fi
done

if [ $counter -eq 5 ] # mysql service is really not running, checked 5 times
then
echo "mysql service is really not running, checked 5 times" 
echo ssh to produtcion instnaces and change master IP from /etc/hosts

echo Modifying master IP in self /etc/hosts and copy that file on all other production instnaces.

export old_master=`cat /home/ipdetails.txt | awk '{print $2 " " $1}' | grep -w ^master |  awk '{print $2}'`
export new_master=`cat /home/ipdetails.txt | awk '{print $2 " " $1}' | grep -w ^slave |  awk '{print $2}'`

echo $old_master
echo $new_master

cp $etchost $etchost_bk

sed -i 's/'$old_master'/'$new_master'/g' $etchost

ssh $slave cp -r $etchost $etchost_bk || { echo "Not able to connect to $slave frontend" ; exit; }
scp $etchost root@$slave:$etchost || { echo "Not able to connect to $slave frontend" ; exit; }

echo "promoting slave as master, It will reset master on 3306"
#
##############3306 Port###################
#
mysql -h $slave -u mysqlfo  -pdefault -D mysql -e "stop slave"
mysql -h $slave -u mysqlfo  -pdefault -D mysql -e "reset slave"
ssh $slave "service mysqld stop"
ssh $slave cp -r $Mycnf $Mycnfold
ssh $slave mv -f $Mycnfpromote $Mycnf
ssh $slave "service mysqld start"
mysql -h $slave -u mysqlfo  -pdefault -D mysql -e "reset master"
mysql -h $slave -u mysqlfo  -pdefault -e "change master to master_host=''"

#change hostname of promoted host in /etc/sysconfig/network file and as kernel parameter

cat /etc/hosts > /home/ipdetails.txt
networkhostname="/etc/sysconfig/network"
export slave=`cat /home/ipdetails.txt | awk '{print $2 " " $1}' | grep -w ^slave |  awk '{print $2}'`
export newhostname=`cat /home/ipdetails.txt | awk '{print $3 " " $1}' | grep -w ^master |  awk '{print $1}'`
export slavename=`cat /home/ipdetails.txt | awk '{print $3 " " $1}' | grep -w ^slave |  awk '{print $1}'`
echo $newhostname
ssh $slave "sysctl kernel.hostname=$newhostname"
ssh $slave "sed -i 's/'$slavename'/'$newhostname'/g' $networkhostname"

echo done

sh /home/master-failure-application-pointing-script.sh > /mnt/scriptslog/master-failure-application-pointing-script.log

##

/usr/sbin/sendmail -oi -t << EOF
From: Production_Master
To: nic-ogpl@nic.in,opengovplatform@gmail.com
Subject: Alert, Master MySQL $master services are not accessible.

Alert, Master MySQL services are not accessible. Took necessary action and made changes in /etc/hosts on all servers.
Please check log files for more details.
EOF

echo "Made the necessary changes and sent the email."

else
echo "########################################################################################################"
echo "MySQL services on $master  found to be working as expected at `date` ... hence nothing to do."
echo "########################################################################################################"
fi

cat /etc/hosts > /home/ipdetails.txt

export master=`cat /home/ipdetails.txt | awk '{print $2 " " $1}' | grep -w ^master |  awk '{print $2}'`

mysql  -h $master -u mysqlfo  -pdefault -D mysql -e "select * from user" > /home/outputfile.txt
export filesize=`ls -lah /home/outputfile.txt | awk '{ print $5 }'`
echo $filesize
if [ "$filesize" = "0" ]
then
	sleep 15
	mysql  -h $master -u mysqlfo  -pdefault -D mysql -e "select * from user" > /home/outputfile.txt
	export filesize=`ls -lah /home/outputfile.txt | awk '{ print $5 }'`
	echo $filesize
	if [ "$filesize" = "0" ]
	then
echo "File size is zero,means even mysql status is running there are lot of queries in queue and because of that this query has not executed. Need to chnage the configuration files."

echo Taking backup of existing config.inc.php on both left and right front ends

export old_master=`cat /home/ipdetails.txt | awk '{print $2 " " $1}' | grep -w ^master |  awk '{print $2}'`
export new_master=`cat /home/ipdetails.txt | awk '{print $2 " " $1}' | grep -w ^slave |  awk '{print $2}'`

echo $old_master
echo $new_master

cp $etchost $etchost_bk

sed -i 's/'$old_master'/'$new_master'/g' $etchost

ssh $slave cp -r $etchost $etchost_bk || { echo "Not able to connect to $slave frontend" ; exit; }
scp $etchost root@$slave:$etchost || { echo "Not able to connect to $slave frontend" ; exit; }

echo "slave as master, It will reset master on 3306"
#
##############3306 Port###################
#
mysql -h $slave -u mysqlfo  -pdefault -D mysql -e "stop slave"
mysql -h $slave -u mysqlfo  -pdefault -D mysql -e "reset slave"
ssh $slave "service mysqld stop"
ssh $slave cp -r  $Mycnf $Mycnfold
ssh $slave mv -f $Mycnfpromote $Mycnf
ssh $slave "service mysqld start"
mysql -h $slave -u mysqlfo  -pdefault -D mysql -e "reset master"
mysql -h $slave -u mysqlfo  -pdefault -e "change master to master_host=''"

#change hostname of promoted host in /etc/sysconfig/network file and as kernel parameter

cat /etc/hosts > /home/ipdetails.txt
networkhostname="/etc/sysconfig/network"
export slave=`cat /home/ipdetails.txt | awk '{print $2 " " $1}' | grep -w ^slave |  awk '{print $2}'`
export newhostname=`cat /home/ipdetails.txt | awk '{print $3 " " $1}' | grep -w ^master |  awk '{print $1}'`
export slavename=`cat /home/ipdetails.txt | awk '{print $3 " " $1}' | grep -w ^slave |  awk '{print $1}'`
echo $newhostname
ssh $slave "sysctl kernel.hostname=$newhostname"
ssh $slave "sed -i 's/'$slavename'/'$newhostname'/g' $networkhostname"


echo done

sh /home/master-failure-application-pointing-script.sh > /mnt/scriptslog/master-failure-application-pointing-script.log

/usr/sbin/sendmail -oi -t << EOF
From: Production_Master
To: nic-ogpl@nic.in,opengovplatform@gmail.com
Subject: Alert, Master MySQL $master queries in queue

Alert,Though system showing mysql master is running,we did not get the output of our default query means there are lot of queries in queue. Took necessary action and made changes in /etc/hosts files
Please check log files located at /mnt/failover-logs/ for more details.
Please check log files for more details.
EOF
echo "Made the necessary changes and sent the email."
fi

else
echo "File size of our query output is $filesize, it is non zero means query ran successfully.This states that mysql running properly and there are no queries in queue "
echo "Now we will clear the contetns of that files"
> /home/outputfile.txt
export filesizenew=`ls -lah /home/outputfile.txt | awk '{ print $5 }'`
echo "contents from the file are removed, now size of file is $filesizenew"
fi
