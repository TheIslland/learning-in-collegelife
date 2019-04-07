#!/bin/bash
startTime=$(date +%Y-%m-%d-%H-%M-%S)
pathName="/data/cpu_logs"
fileName="$pathName/CPUINFO_$startTime.csv"
 
# create dir
if [ ! -d $pathName ]; then
	mkdir -p $pathName
	chmod 777 $pathName
fi
 
#cat /proc/kmsg > /data/local/cpu_logs/1/SOC_kernel.log &
#cat /proc/kmsg > /data/SOC_kernel.log &
 
# write title to file
titleName="TIME,EMMC_THERM,POPMEM,CAMERA,MODEM,CPU0,CPU1,CPU2,CPU3,CPU4,CPU5,CPU6,CPU7,\
CPU0FREQ,CPU1FREQ,CPU2FREQ,CPU3FREQ,CPU4FREQ,CPU5FREQ,CPU6FREQ,CPU7FREQ,GPU0,GPU1,GPUFREQ,SOC,Bat_TEMP,Bat_current"
echo $titleName>> $fileName
 
while [ 1 ]; do
	sleep 1
	deltaTime=$(date +%H:%M:%S)
	CPUONLINE=$(cat /sys/devices/system/cpu/online)
	LCD=$(cat /sys/class/leds/lcd-backlight/brightness)
	BMS=$(($(cat /sys/devices/virtual/thermal/thermal_zone0/temp) / 1000))	# change to C
	Bat_TEMP=$(($(cat /sys/devices/virtual/thermal/thermal_zone1/temp) / 1000))
	Hexagon1=$(cat /sys/devices/virtual/thermal/thermal_zone3/temp)
	EMMC_THERM=$(cat /sys/devices/virtual/thermal/thermal_zone20/temp)
	POPMEM=$(cat /sys/devices/virtual/thermal/thermal_zone4/temp)
	CAMERA=$(cat /sys/devices/virtual/thermal/thermal_zone5/temp)
	MDSS=$(cat /sys/devices/virtual/thermal/thermal_zone6/temp)
	MODEM=$(cat /sys/devices/virtual/thermal/thermal_zone7/temp)
	CPU0=$(cat /sys/devices/virtual/thermal/thermal_zone9/temp)
	CPU1=$(cat /sys/devices/virtual/thermal/thermal_zone10/temp)
	CPU2=$(cat /sys/devices/virtual/thermal/thermal_zone11/temp)
	CPU3=$(cat /sys/devices/virtual/thermal/thermal_zone12/temp)
	CPU4=$(cat /sys/devices/virtual/thermal/thermal_zone15/temp)
	CPU5=$(cat /sys/devices/virtual/thermal/thermal_zone16/temp)
	CPU6=$(cat /sys/devices/virtual/thermal/thermal_zone17/temp)
	CPU7=$(cat /sys/devices/virtual/thermal/thermal_zone8/temp)
	GPU0=$(cat /sys/devices/virtual/thermal/thermal_zone13/temp)
	GPU1=$(cat /sys/devices/virtual/thermal/thermal_zone14/temp)
	PM8994_TZ=$(($(cat /sys/devices/virtual/thermal/thermal_zone18/temp) / 1000))	
	Bat_current=$(cat /sys/class/power_supply/battery/current_now)
	SOC=$(cat /sys/class/power_supply/battery/capacity)
	GPUFREQ=$(($(cat /sys/class/kgsl/kgsl-3d0/gpuclk) / 1000)) # change to KHz
	
	if [ -d /sys/devices/system/cpu/cpu0/cpufreq ]; then
	CPU0FREQ=$(cat /sys/devices/system/cpu/cpu0/cpufreq/scaling_cur_freq)
	else
	CPU0FREQ="0"
	fi
	if [ -d /sys/devices/system/cpu/cpu1/cpufreq ]; then
	CPU1FREQ=$(cat /sys/devices/system/cpu/cpu1/cpufreq/scaling_cur_freq)
	else
	CPU1FREQ="0"
	fi
	if [ -d /sys/devices/system/cpu/cpu2/cpufreq ]; then
	CPU2FREQ=$(cat /sys/devices/system/cpu/cpu2/cpufreq/scaling_cur_freq)
	else
	CPU2FREQ="0"
	fi
	if [ -d /sys/devices/system/cpu/cpu3/cpufreq ]; then
	CPU3FREQ=$(cat /sys/devices/system/cpu/cpu3/cpufreq/scaling_cur_freq)
	else
	CPU3FREQ="0"
	fi
	if [ -d /sys/devices/system/cpu/cpu4/cpufreq ]; then
	CPU4FREQ=$(cat /sys/devices/system/cpu/cpu4/cpufreq/scaling_cur_freq)
	else
	CPU4FREQ="0"
	fi
	if [ -d /sys/devices/system/cpu/cpu5/cpufreq ]; then
	CPU5FREQ=$(cat /sys/devices/system/cpu/cpu5/cpufreq/scaling_cur_freq)
	else
	CPU5FREQ="0"
	fi
	if [ -d /sys/devices/system/cpu/cpu6/cpufreq ]; then
	CPU6FREQ=$(cat /sys/devices/system/cpu/cpu6/cpufreq/scaling_cur_freq)
	else
	CPU6FREQ="0"
	fi
	if [ -d /sys/devices/system/cpu/cpu7/cpufreq ]; then
	CPU7FREQ=$(cat /sys/devices/system/cpu/cpu7/cpufreq/scaling_cur_freq)
	else
	CPU7FREQ="0"
	fi
	
	echo "$deltaTime,$EMMC_THERM,$POPMEM,$CAMERA,$MODEM,$CPU0,$CPU1,$CPU2,$CPU3,$CPU4,$CPU5,$CPU6,$CPU7,\
$CPU0FREQ,$CPU1FREQ,$CPU2FREQ,$CPU3FREQ,$CPU4FREQ,$CPU5FREQ,$CPU6FREQ,$CPU7FREQ,$GPU0,$GPU1,$GPUFREQ,$SOC,$Bat_TEMP,$Bat_current">> $fileName
 
	echo "$deltaTime,$EMMC_THERM,$POPMEM,$CAMERA,$MODEM,$CPU0,$CPU1,$CPU2,$CPU3,$CPU4,$CPU5,$CPU6,$CPU7,\
$CPU0FREQ,$CPU1FREQ,$CPU2FREQ,$CPU3FREQ,$CPU4FREQ,$CPU5FREQ,$CPU6FREQ,$CPU7FREQ,$GPU0,$GPU1,$GPUFREQ,$SOC,$Bat_TEMP,$Bat_current"	
done
 

