#!/bin/bash
time=`date +%Y-%m-%d__%H:%M:%S` # 时间
cpu_1=`cat /proc/stat | awk '{if(NR==1) for(i=2;i<=NF;i++)printf("%s ",$i)}'`
sleep 0.5
cpu_2=`cat /proc/stat | awk '{if(NR==1) for(i=2;i<=NF;i++)printf("%s ",$i)}'`
total_1=`echo $cpu_1 | awk '{for(i=1;i<=NF;i++)sum+=$i}END{printf("%.f",sum)}'`
total_2=`echo $cpu_2 | awk '{for(i=1;i<=NF;i++)sum+=$i}END{printf("%.f",sum)}'`
idle_1=`echo $cpu_1 | cut -d " " -f4`
idle_2=`echo $cpu_2 | cut -d " " -f4`
((total=$total_2 - $total_1))
((idle=$idle_2 - $idle_1))
((cpu_usage=$idle \* 100 / $total ))
((cpu_usage=100 - $cpu_usage))
cpuload=(`cat /proc/loadavg | awk '{print $1,$2,$3}'`)
load1=${cpuload[0]}
load5=${cpuload[1]}
load15=${cpuload[2]}
cpu_temp=`cat /sys/class/thermal/thermal_zone0/temp | awk '{printf("%d",$1/1000)}'`
if [[ $cpu_temp -le 50  ]]; then 
cpu_state="normal"
elif [[ $cpu_temp -le 70  ]]; then
cpu_temp="note"
else
cpu_state="warning"
fi
echo "$time $load1 $load5 $load15 $cpu_usage ${cpu_temp}C $cpu_state"
