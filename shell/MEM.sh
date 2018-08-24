#!/bin/bash
time=`date +%Y-%m-%d__%H:%M:%S`
total=`free -m | awk '{if(NR==2) print $2}'`
use=`free -m | awk '{if(NR==2) print $4}'`
(( used=total-use))
(( zhanyong=used*100/total ))
echo -n "$time $total $use $zhanyong% "
echo "scale=1;0.3*$1+0.7$zhanyong" | bc

