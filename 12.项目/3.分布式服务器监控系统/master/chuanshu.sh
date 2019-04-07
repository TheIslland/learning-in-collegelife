#!/bin/bash
for i in `seq 11 20`; do
    scp ~/learning-in-collegelife/12.项目/3.分布式服务器监控系统/master/client.c pi$i:~/
#    scp ~/learning-in-collegelife/12.项目/3.分布式服务器监控系统/master/User_information_statistics.sh pi$i:~/
#    scp ~/learning-in-collegelife/12.项目/3.分布式服务器监控系统/master/DISK.sh pi$i:~/
#    scp ~/learning-in-collegelife/12.项目/3.分布式服务器监控系统/master/cpu_occupy.sh pi$i:~/
#    scp ~/learning-in-collegelife/12.项目/3.分布式服务器监控系统/master/MEM.sh pi$i:~/
#    scp ~/learning-in-collegelife/12.项目/3.分布式服务器监控系统/master/malicious_process_detection.sh pi$i:~/
#    scp ~/learning-in-collegelife/12.项目/3.分布式服务器监控系统/master/System_operation.sh pi$i:~/
done
