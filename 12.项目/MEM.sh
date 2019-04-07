#!/bin/bash

time=`date +%Y-%m-%d__%H:%M:%S` # 当前时间
total=(`free -m | head -n 2 | tail -n 1 | awk '{printf $2" "$4}'`) # 总量 剩余量
current_occupancy=$(echo "scale=1;$[${total[0]}-${total[1]}]*100/${total[0]}" | bc) # 当前占用
dynamic=$(echo "scale=1;0.3*20+0.7*$current_occupancy" | bc) # 占用百分比动态平均值

echo $time ${total[0]}M ${total[1]}M $current_occupancy% $dynamic%
