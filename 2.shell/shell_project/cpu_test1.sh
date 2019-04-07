#!/bin/bash
#!/bin/bash
interval=2
numbers=`cat /proc/stat | grep cpu[0-9] -c`

if [ $# -ne 1 ];then
    exit 1
fi

if [ ${1} -lt ${numbers} ];then
    num=$1
    cpu_num=`expr ${1} + 1`    

    start_idle=()
    start_total=()
    cpu_rate=()

    for((i=${num};i<${cpu_num};i++))
    {
        start=$(cat /proc/stat | grep "cpu$i" | awk '{print $2" "$3" "$4" "$5" "$6" "$7" "$8}')
        start_idle[$i]=$(echo ${start} | awk '{print $4}')
        start_total[$i]=$(echo ${start} | awk '{printf "%.f",$1+$2+$3+$4+$5+$6+$7}')
    }
    start=$(cat /proc/stat | grep "cpu " | awk '{print $2" "$3" "$4" "$5" "$6" "$7" "$8}')
    start_idle[${cpu_num}]=$(echo ${start} | awk '{print $4}')
    start_total[${cpu_num}]=$(echo ${start} | awk '{printf "%.f",$1+$2+$3+$4+$5+$6+$7}')
    sleep ${interval}
    for((i=${num};i<${cpu_num};i++))
    {
        end=$(cat /proc/stat | grep "cpu$i" | awk '{print $2" "$3" "$4" "$5" "$6" "$7" "$8}')
        end_idle=$(echo ${end} | awk '{print $4}')
        end_total=$(echo ${end} | awk '{printf "%.f",$1+$2+$3+$4+$5+$6+$7}')
        idle=`expr ${end_idle} - ${start_idle[$i]}`
        total=`expr ${end_total} - ${start_total[$i]}`
        idle_normal=`expr ${idle} \* 100`
        cpu_usage=`expr ${idle_normal} / ${total}`
        cpu_rate[$i]=`expr 100 - ${cpu_usage}`
        echo "${cpu_rate[$i]}"
       echo "The CPU$cpu_num Rate : ${cpu_rate[$i]}%"
    }
else
    exit 1
fi
