#!/bin/bash
IP=192.168.2 #定义变量
for i in `seq 0 255`; do
ping -c 2 $IP.$i 2>&1 >/dev/null #0标准输入，1标准输出，2标准错误输出，将标准错误输出加到标准输出中存到/dev/null中
    if [[ $? -eq 0 ]]; then
        echo "$IP.$i"
    fi
done
