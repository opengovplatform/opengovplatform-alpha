#!/bin/bash
                                             
# THIS SCRIPT BELONGS TO NIC. Any unauthorized use, reproduction,
# modification, or disclosure of this script is strictly prohibited.
# Any use of this script by an authorized licensee is strictly subject to the
# terms and conditions, including confidentiality obligations, set forth in
# the applicable License Agreement between UnitedSample Inc. and the licensee.


etchost="/etc/hosts"
etchost_bk="/etc/hosts.org"

cat /etc/hosts > /home/ipdetails.txt

export demodatafe1=`cat /home/ipdetails.txt | awk '{print $2 " " $1}' | grep -w ^demodatafe1 |  awk '{print $2}'`
export demodatafe2=`cat /home/ipdetails.txt | awk '{print $2 " " $1}' | grep -w ^demodatafe2 |  awk '{print $2}'`
export lb1=`cat /home/ipdetails.txt | awk '{print $2 " " $1}' | grep -w ^lb1 | awk '{print $2}'`

ssh $demodatafe1 cp -r $etchost $etchost_bk || { echo "Not able to connect to $demodatafe1 frontend" ; exit; }
scp $etchost root@$demodatafe1:$etchost || { echo "Not able to connect to $demodatafe1 frontend" ; exit; }

ssh $demodatafe2 cp -r $etchost $etchost_bk || { echo "Not able to connect to $demodatafe2 frontend" ; exit; }
scp $etchost root@$demodatafe2:$etchost || { echo "Not able to connect to $demodatafe2 frontend" ; exit; }

ssh $lb1 cp -r $etchost $etchost_bk || { echo "Not able to connect to $lb1 frontend" ; exit; }
scp $etchost root@$lb1:$etchost || { echo "Not able to connect to $lb1 frontend" ; exit; }

/usr/sbin/sendmail -oi -t << EOF
From: Production_environment_monitor
To: nic-ogpl@nic.in,opengovplatform@gmail.com
Subject: Alert,demodata and demodatacms applications pointed to new master server

FYI, Mysql service from master was not accessible. Took necessary action and tried to restart it but could not able to start it so ran mysql promote scripts on slave server and pointed all FEs to new master.
Please check log files for more details.
EOF
