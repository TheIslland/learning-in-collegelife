#!/bin/bash
cat >> /etc/bash.bashrc << EOF
echo -n "`who am i`" >> log.txt
EOF
cat >> /.bash_logout << EOF
i=`who am i | awk '{print $3" "$4}'`
time=$[$(date +%s)-$(date -d "$i" +%s)]
echo "登录时长为：$[$time/60]" >> log.txt
EOF

