echo "####################################################### Replication Monitoring Script for Production Slave Server #####################################"
sleep 5

export slave=`cat /home/ipdetails.txt | awk '{print $2 " " $1}' | grep -w ^slave |  awk '{print $2}'`

counter=0
flag='true'
while [ $counter -lt 5 ]
do
	Slave_IO_Running=`mysql -h $slave -u mysqlfo  -pdefault -D mysql -e "show slave status \G" | grep Slave_IO_Running | awk '{print $2}'`
	Slave_SQL_Running=`mysql -h $slave -u mysqlfo  -pdefault -D mysql -e "show slave status \G" | grep Slave_SQL_Running | awk '{print $2}'`
	if [[ $Slave_IO_Running = 'Yes'  &&  $Slave_SQL_Running = 'Yes' ]]
	then
		flag='true'
		counter=$((counter+1))
	else
		flag='false'
		counter=$((counter+1))
	fi
	sleep 1
done

if [ $flag = 'false' ]
then

/usr/sbin/sendmail -oi -t << EOF
From:Production Slave
To: to nic-ogpl@nic.in,opengovplatform@gmail.com
Subject: Alert, Replication not working on Production slave

Alert, Replication not working on slave. Please login to the system to check issue.
EOF
	echo "Replication Script executed at `date`"
        echo "Replication is not working"
        echo "Slave_IO_Running=$Slave_IO_Running"
        echo "Slave_SQL_Running=$Slave_SQL_Running"
	echo "Alert Mail sent"
else
	echo "Replication Script executed at `date`"
        echo "Replication is running fine as the value of Slave_IO_Running and  Slave_SQL_Running is Yes."
fi
