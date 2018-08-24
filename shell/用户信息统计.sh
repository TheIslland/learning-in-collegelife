#!/bin/bash
time=`date +%Y-%m-%d__%H:%M:%S`
y_num=`who | cut -d' ' -f1 | sort | uniq |id | awk '{print $1}' | wc -l`
three_num=`last | cut -d' ' -f1 |grep "[a-z]"| grep -v "wtmp" | grep -v "reboot" | sort | uniq -c | awk '{if(RN<=3) print $2}'`
root_id=`last | cut -d' ' -f1 |grep "[a-z]"| grep -v "wtmp" | grep -v "reboot" | sort | uniq | id | awk '{print $1}' | cut -d '(' -f2 | cut -d ')' -f1`
information=`who | awk '{print $1"_"$5"_"$2}'`
echo "$time $y_num $three_num $root_id $information"
