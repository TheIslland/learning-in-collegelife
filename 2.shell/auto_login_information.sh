#!/bin/bash
echo -n "`who am i | awk '{print $3" "$4" "$1" "$2" "$5 }'`" >> log.txt
i=`who am i | awk '{print $3" "$4}'`
time=$[$(date +%s)-$(date -d "$i" +%s)]
echo "登录时长为：$[$time/60] min" >> log.txt
#/etc/bash.brashrc
#./bash_logout

