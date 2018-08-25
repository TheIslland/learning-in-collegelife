#!/bin/bash
time=`date +%Y-%m-%d__%H:%M:%S` # 当前时间
y_num=`cat /etc/passwd | cut -d ':' -f3 | awk '{if($1>=1001) print $1}' | wc -l` # 计算登录的用户总人次
three_num=`last | cut -d' ' -f1 |grep "[a-z]"| grep -v "wtmp" | grep -v "reboot" | sort | uniq -c | awk '{if(RN<=3) print $2}'` # 将活跃用户的前三位存入数组 
root_id=`last | cut -d' ' -f1 |grep "[a-z]"| grep -v "wtmp" | grep -v "reboot" | sort | uniq | id | awk '{print $1}' | cut -d '(' -f2 | cut -d ')' -f1` # 当前具有root权限的用户
information=`who | awk '{print $1"_"$5"_"$2}'` # 将当前在线用户的IP等信息存入数组
echo "$time $y_num $three_num $root_id $information" # 输出当前在线用户的IP等信息
