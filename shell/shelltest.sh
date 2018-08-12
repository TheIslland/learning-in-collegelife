#!/bin/bash
num=0
sum=0
for(( i = 2; i < 10000; i++ )); do
    b=0
    for(( j = 2; j*j <= i; j++ )); do
        if [[ i%j -eq 0 ]]; then
            b=1 
            break
        fi    
    done
    if [[ b -eq 0 ]]; then
        (( num+=1 ));
        (( sum=sum+i ));
        echo $i
    fi
done
echo $num
echo $sum
#shell语法练习--循环与判断的初次尝试
#表达式放在((  ));中可以进行c语言写法，严格控制空格的使用
#shell中任然可以使用break在循环和判断外使用需要在((  ));中
#注意输出时应该加$符号取值
#判断条件后面应该有空格

