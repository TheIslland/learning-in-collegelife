#!/bin/bash

time=`date +%Y-%m-%d__%H:%M:%S` # 当前时间
user_num=`last | grep "[a-zA-Z]" | grep -v "wtmp" | grep -v "reboot" | cut -d " " -f 1 | wc -l` # 计算登录用户总人次
active_user=(`last | cut -d " " -f 1 | grep "[a-zA-Z0-9]" | grep -v "wtmp" | grep -v "reboot" | sort | uniq -c | awk '{if(RN<=3) print $2}'`) # 将活跃用户的前三位存入数组 
root_user=`last | cut -d " " -f 1 | grep "[a-zA-Z0-9]" | grep -v "wtmp" | grep -v "reboot" | sort | uniq | id | awk '{print $1}' | cut -d '(' -f 2 | cut -d ')' -f 1` # 当前具有root权限的用户
IP=(`who | awk '{print $1"_"$5"_"$2}'`) # 将当前在线用户的IP等信息存入数组
IP_num=`who -q | tail -n 1 | cut -d "=" -f 2` # 计算当前在线用户总数

echo -e "$time $user_num [""\c"

for i in {0..2}; do # 输出活跃用户最多输出三个
    if [[ ${active_user[$i]} ]]; then
        if [[ $i -ne 0 ]]; then
            echo -e ",""\c"
        fi
        echo -e "${active_user[$i]}""\c"
    fi
done
echo -e "]" "\c"

echo -e "[$root_user] [""\c"

((IP_num=$IP_num-1))
for i in `seq 0 $IP_num`; do # 输出当前在线用户的IP等信息
    if [[ $i -ne 0 ]]; then
        echo -e ",""\c"
    fi
    echo -e "${IP[$i]}""\c"
done
echo "]"
