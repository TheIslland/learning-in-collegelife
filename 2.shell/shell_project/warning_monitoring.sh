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
cpu_temp=`cat /sys/class/thermal/thermal_zone0/temp | awk '{printf("%d",$1/1000)}'`
MEM_total=`free -m | awk '{if(NR==2) printf("%s %s",$2,$3)}'`
MEM_used=`echo ${MEM_total[0]} | cut -d " " -f2`
MEM_total=`echo ${MEM_total[0]} | cut -d " " -f1`
(( MEM_use=$MEM_total-$MEM_used))
(( MEM_proportion=MEM_use*100/$MEM_total ))
if [[ $proportion -le 80 ]]; then 
    echo "DISK normal"
elif [[ $proportion -le 90 ]]; then
    echo "DISK note"
else
    echo "DISK warning"
fi
if [[ $cpu_temp -le 50 ]]; then 
    echo "cpu normal"
elif [[ $cpu_temp -le 70 ]]; then
    echo "cpu note"
else
    echo "cpu warning"
fi
if [[ $MEM_proportion -le 70 ]]; then 
    echo "MEM normal"
elif [[ $MEM_proportion -le 80 ]]; then
    echo "MEM note"
else
    echo "MEM warning"
fi
