#!/bin/bash

arr_1=(`ps aux | awk '{if($3 > 50 || $4 > 50) print $2}'`)
sleep 5
arr_2=(`ps aux | awk 'NR>1{if($3 > 50 || $4 > 50) print $11","$2","$1","$3","$4}'`)

time=`date "+%Y-%m-%d__%H:%M:%S"`

for i in `seq 0 $[${#arr_2[@]}-1]`; do
    PID=`echo ${arr_2[$i]} | cut -d"," -f 2`
    for j in `seq 0 $[${#arr_1[@]}-1]`; do
        if [[ ${arr_1[$j]} -eq $PID ]]; then
            cpu=`echo ${arr_2[$i]} | cut -d"," -f4`
            mem=`echo ${arr_2[$i]} | cut -d"," -f5`
            cpu=$(echo "scale=2;1.00*$cpu" | bc)
            mem=$(echo "scale=2;1.00*$mem" | bc)
            echo $time `echo ${arr_2[$i]} | cut -d"," -f1-3 | tr "," " "` $cpu"%" $mem"%"
        fi
    done
done
