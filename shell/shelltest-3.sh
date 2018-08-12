#!/bin/bash
prime=(`seq 1 10000`)
for (( i = 0; i < 10000; i++ )); do
    prime[$i]=0
done
for (( i = 2; i < 10000; i++ )); do
    if [[ prime[i] -eq 0 ]]; then
        (( ++prime[0] ));
        prime[${prime[0]}]=$i
    fi
    for (( j = 1; j <= prime[0]; j++ )); do
        if [[ prime[j]*i -gt 10000 ]]; then
            break
        fi
        prime[$i*${prime[$j]}]=1
        if [[ i%prime[j] -eq 0 ]]; then
            break
        fi
    done
done
echo ${prime[0]}
for (( i=1; i<prime[0]; i++ )); do
    echo ${prime[$i]}
done
#$符只有在去变量值的时候使用
#$符后如果为数组的话应该加{}将数组包括指明范围
#被赋值的对象不能加$符

