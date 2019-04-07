#!/bin/bash

time=`date +%Y-%m-%d__%H:%M:%S`
total=(`free -m | awk '{printf $2" "}'`)
free=(`free -m | awk '{print $4" "}'`)
zy=$[$[${total[1]}-${free[1]}]*100/${total[1]}]

echo -e "$time" "${total[1]}M" "${free[1]}M" "$zy%" "\c"
echo "scale=1;0.3*$1+0.7*$zy" | bc
