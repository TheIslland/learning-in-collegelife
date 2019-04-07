#!/bin/bash
time=`date +%Y-%m-%d__%H:%M:%S` # 时间
information=(`df -T -x devtmpfs -m -x tmpfs | tail -n +2 | awk '{printf("a["NR"]=%s,%d,%d,%s ",$7,$3,$5,$6)}'`) # 磁盘分区信息
disk_total=0 # 磁盘内存总量
used_disk=0 # 磁盘可用内存
((len=${#information[@]}-1)) # 分区总数
for((i=0;i<=len;i++)); do
    ((disk_total=$disk_total+`echo ${information[$i]} | cut -d "," -f 2`)) #磁盘总量
    ((used_disk=$used_disk+`echo ${information[$i]} | cut -d "," -f 3`)) #磁盘可用内存
done
((proportion=($disk_total-$used_disk)*100/$disk_total)) #占用比
echo "$time 0 disk $disk_total $used_disk $proportion%" #磁盘信息
for((j=0;j<=len;j++)); do
    echo "$time 1 `echo ${information[j]} | cut -d "=" -f 2 | tr "," " "`" #分区信息
done

