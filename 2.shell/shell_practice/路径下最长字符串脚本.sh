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
    fi #进行了递归调用以达到目录的遍历
    if [[ -f "$i" ]]; then
        for j in `strings "$i"`; do #如果参数中含有多个空格，在参数外加上双引号" "，可将其视为一个整体 解决了可靠性验证的问题
            #strings自动转换为字符串型
		    mid=0
		    mid=${#j} #用mid存储当前长度
		    if [[ mid -gt length ]]; then #比较 
                length=$mid
                temp=$j
                way=`pwd` #存储路径
                name=$i
            fi
	    done
    fi
done
return
}

cd $1 #跳转到要遍历的路径
find #调用函数
echo "输出最长字符串："
echo $temp #输出最长字符串
echo "输出最长字符串长度："
echo $length #输出最长字符串长度
echo "输出其路径："
echo $way #输出其路径
echo "输出其文件名："
echo $name #输出其文件名
