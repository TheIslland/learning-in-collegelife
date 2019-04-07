#!/bin/bash
showhelp()
{
echo '帮助: '
echo 'OPTIONS:'
echo '-a : 每个CPU使用率'
echo '-t : 总体使用率'
echo '数字 :某一个CPU使用率'
}


get_cpu_rate()
{
#interval,获取cpu 使用的时间间隔； 
interval=1
#获取cpu数目
cpu_num=`cat /proc/stat | grep cpu[0-9] -c`


#cpu等待时间数组
start_idle=()
#cpu使用总时间数组
start_total=()
#cpu使用率数组
cpu_rate=()
#计算初始每个cpu使用数据
    for((i=0;i<${cpu_num};i++))
    {
        start=$(cat /proc/stat | grep "cpu$i" | awk '{print $2" "$3" "$4" "$5" "$6" "$7" "$8}')
        start_idle[$i]=$(echo ${start} | awk '{print $4}')
        start_total[$i]=$(echo ${start} | awk '{printf "%.f",$1+$2+$3+$4+$5+$6+$7}')
    }
 #计算初始总cpu使用数据 
    start=$(cat /proc/stat | grep "cpu " | awk '{print $2" "$3" "$4" "$5" "$6" "$7" "$8}')
    start_idle[${cpu_num}]=$(echo ${start} | awk '{print $4}')
    start_total[${cpu_num}]=$(echo ${start} | awk '{printf "%.f",$1+$2+$3+$4+$5+$6+$7}')
#interval时间后
    sleep ${interval}
#计算时间间隔后每个cpu使用数据,并根据数据计算出每个CPU使用率   
    for((i=0;i<${cpu_num};i++))
    {
        end=$(cat /proc/stat | grep "cpu$i" | awk '{print $2" "$3" "$4" "$5" "$6" "$7" "$8}')
        end_idle=$(echo ${end} | awk '{print $4}')
        end_total=$(echo ${end} | awk '{printf "%.f",$1+$2+$3+$4+$5+$6+$7}')
        idle=`expr ${end_idle} - ${start_idle[$i]}`
        total=`expr ${end_total} - ${start_total[$i]}`
cpu_usage=`expr ${idle} \* 100 / ${total}`
        cpu_rate[$i]=`expr 100 - ${cpu_usage}`
       # echo cpu$i:${cpu_rate[$i]}
    }
 #计算时间间隔后总cpu使用数据，并根据数据计算出计算机所有CPU的总体使用率  
    end=$(cat /proc/stat | grep "cpu " | awk '{print $2" "$3" "$4" "$5" "$6" "$7" "$8}')
    end_idle=$(echo ${end} | awk '{print $4}')
    end_total=$(echo ${end} | awk '{printf "%.f",$1+$2+$3+$4+$5+$6+$7}')
    idle=`expr ${end_idle} - ${start_idle[$i]}`
    total=`expr ${end_total} - ${start_total[$i]}`
    cpu_usage=`expr  ${idle} \* 100 / ${total}`
    cpu_rate[${cpu_num}]=`expr 100 - ${cpu_usage}`
    echo "${cpu_rate[${cpu_num}]}" #返回总体使用率
 
 while [ $1 ]; do
case $1 in
'-a'  )
for((i=0;i<${cpu_num};i++))
{
echo "cpu$i:${cpu_rate[$i]}"
}
exit
;;
*[0-9]* )
echo "cpu$1:${cpu_rate[$1]}"
exit
;;
'-t' )
echo "total cpu rate:${cpu_rate[${cpu_num}]}"
exit
;; 
* )
showhelp
exit
;;
esac
shift
done   
}


while true; do 
   #echo $(get_cpu_rate)
   #read var <<< $(get_cpu_rate)
  # echo "CPU rate:" $var
  read var <<< $(get_cpu_rate -t)
  echo $var
 done
