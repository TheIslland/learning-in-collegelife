#!/bin/bash
cpu_1=`cat /proc/stat | awk '{if(NR==1) for(i=2;i<=NF;i++)printf("%s ",$i)}'`
sleep 1
cpu_2=`cat /proc/stat | awk '{if(NR==1) for(i=2;i<=NF;i++)printf("%s ",$i)}'`
total_1=`echo $cpu_1 | awk '{for(i=1;i<=NF;i++)sum+=$i}END{printf("%.f",sum)}'`
total_2=`echo $cpu_2 | awk '{for(i=1;i<=NF;i++)sum+=$i}END{printf("%.f",sum)}'`
idle_1=`echo $cpu_1 | cut -d " " -f4`
idle_2=`echo $cpu_2 | cut -d " " -f4`
((total=$total_2 - $total_1))
((idle=$idle_2 - $idle_1))
((cpu_usage=$idle \* 100 / $total ))
((cpu_usage=100 - $cpu_usage))
echo "$cpu_usage"

