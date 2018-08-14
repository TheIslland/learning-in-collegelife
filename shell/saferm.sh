#!/bin/bash
if [[ ! -d ~/.trash ]]; then
    mkdir ~/.trash
fi #判断垃圾桶是否存在没有就建一个
if [ $# == 0 ]
then
    echo "用法 rm file1 [file2 file3]" #如果没有传入参数就输出用法
elif [ $1 = "-r" ] && [ $2 = "-f*" ] #识别特殊选项-r -f*
    then
    #way=`pwd`
    for num in `ls`; do
        if [ -f "$num" ] || [ -d "$num" ]
        then 
            mv -b "$num" ~/.trash/
        fi
    done
    #mv saferm.ssh $way
elif [ $1 = "-f" ] #识别选项-f
    then
        for file in "$@"; do
            if [ $file = "-f" ]
            then 
                continue;
            fi
            mv -b "$file" ~/.trash/
        done
else 
    echo "你即将删除以下文件"
    echo $@
    echo "确定要删除此文件吗？[Y/n]:"
    read decide
    if [ "$decide" = "Y" ] || [ "$decide" = "y" ] #判断是否进行删除
    then
        for file in "$@"; do
            if [ -f "$file" ] || [ -d "$file" ] 
            then
                mv -b "$file" ~/.trash/
                else
                    echo "没有找到文件或目录"
            fi
        done
    else
        echo "删除操作已取消"
    fi
fi
