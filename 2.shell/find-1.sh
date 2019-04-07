#!/bin/bash

name=0
ans=0
temp=0
length=0
way=0
find() {
    #``可以将命令的输出取出
for i in `ls`; do #ls时对于有空格的文件名系统自动添加了''
    if [[ -d "$i" ]]; then #判断是否为目录
        cd $i
        find
        cd ..
        continue
    fi
    if [[ -f "$i" ]]; then
        for j in `strings "$i"`; do #如果参数中含有多个空格，在参数外加上双引号" "，可将其视为一个整体 解决了可靠性验证的问题
            #strings自动转换为字符串型
		    mid=0
		    mid=${#j}
		    if [[ mid -gt length ]]; then
                length=$mid
                temp=$j
                way=`pwd`
                name=$i
            fi
	    done
    fi
done
return
}

cd $1
find
echo $temp
echo $length
echo $way
echo $name
