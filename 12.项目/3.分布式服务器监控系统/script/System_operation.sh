#!/bin/bash

time=`date +%Y-%m-%d__%H:%M:%S` # 时间
system_information=(`uname -a | awk '{print $2" "$15" "$3}'`) # 系统信息
up=`uptime -p | tr -d "," | tr " " "_"` # 运行时间
load_average=`uptime | awk '{printf $9$10$11}'` # 平均负载
information=(`df -m -x tmpfs | tail -n +2 | awk '{printf("%d,%d ",$2,$3 )}'`) # 磁盘分区信息
total=(`free -m | grep Mem | awk '{printf $2" "$3}'`) # 内存总量 剩余量
current_occupancy=$[${total[1]}*100/${total[0]}] # 当前内存占用比例
cpu_temperature=$[`cat /sys/class/thermal/thermal_zone0/temp`] # cpu温度
cpu=$(echo "scale=2;$cpu_temperature/1000" | bc) # cpu温度（小数）
cpu_temperature=$[$cpu_temperature/1000] # cpu温度
Alarm=(0 80 90 70 80 50 90) # 警报等级范围 （磁盘占比的两个界限 内存占比的两个界限 cup温度的两个界限）
Percentage=($Occupancy_ratio $current_occupancy $cpu_temperature) # 磁盘占用比例 内存占用比例 cup温度

for i in `seq 0 $[${#information[@]}-1]`; do # $[${#information[@]}-1] 计算总分区数-1
    ((Total_memory=$Total_memory+`echo ${information[$i]} | cut -d "," -f 1`)) # 计算磁盘总量
    ((Occupied_memory=$Occupied_memory+`echo ${information[$i]} | cut -d "," -f 2`)) # 计算已用磁盘量
done
((Occupancy_ratio=$Occupied_memory*100/$Total_memory)) # 计算磁盘占用比例

# 输出系统运行情况
echo -e "$time ${system_information[0]} ${system_information[1]} ${system_information[2]} $up $load_average ${Total_memory}M $Occupancy_ratio% ${total[0]}M $current_occupancy% $cpu""\c"

for i in {0..2}; do # $i是Percentage数组的下标
    ((Alarm[0]=${Alarm[0]}+1)) # 通过Alarm[0]自加 遍历警报等级范围
    if [[ ${Percentage[$i]} -le ${Alarm[${Alarm[0]}]} ]]; then
        echo -e " normal""\c"
        ((Alarm[0]=${Alarm[0]}+1))
    elif ((Alarm[0]=${Alarm[0]}+1)) && [ ${Percentage[$i]} -le ${Alarm[${Alarm[0]}]} ]; then
        echo -e " note""\c"
    else
        echo -e " waring""\c"
    fi
done
echo
