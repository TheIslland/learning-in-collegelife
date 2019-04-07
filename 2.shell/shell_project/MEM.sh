#!/bin/bash
time=`date +%Y-%m-%d__%H:%M:%S`
MEM_total=`free -m | awk '{if(NR==2) printf("%s %s",$2,$3)}'`
MEM_used=`echo ${MEM_total[0]} | cut -d " " -f2`
MEM_total=`echo ${MEM_total[0]} | cut -d " " -f1`
(( MEM_use=$MEM_total-$MEM_used ))
MEM_proportion=`echo "scale=2;$MEM_use*100/$MEM_total" | bc`
echo -n "$time $MEM_total $MEM_used $MEM_proportion% "
echo "scale=1;0.3*$1+0.7*$MEM_proportion" | bc
