##!/bin/bash
time=`date +%Y-%m-%d__%H:%M:%S` # 当前时间
hoster_name=`hostname` #主机名
os_date=`uname -a | cut -d " " -f15`
neihe=`uname -r`
os_date="$os_date $neihe"
up_time=`uptime -p`
arry_load=`uptime | cut -d ":" -f5`
up_time="$up_time$arry_load"
total=`free -m | awk '{if(NR==2) printf("%s %s",$2,$3)}'`
used=`echo $total | cut -d " " -f2`
total=`echo $total | cut -d " " -f1`
(( use=total-used))
(( zhanyong=use*100/total ))
echo -n "$time $total $used $zhanyong% "
echo "scale=1;0.3*24+0.7$zhanyong" | bc

