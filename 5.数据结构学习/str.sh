#!/bin/bash

num=0
str=0
way=0
nl=0
op=(0 0 0 0)

filter() {
    a=(rmvb png img jpg jpeg gif md avi zip tar gz 7z)
    suffix=`echo $1 | awk -F. '{printf}'`
    echo ${a[*]} | grep "suffix" >/dev/null
    if [[ $? -eq 0 ]]; then
        return 1
    fi
    return 0
}

long_str(){
    num=0
    for i in `ls`; do
        if [[ -d $i ]]; then
            cd $i
            long_str
            cd ..
            continue
        fi
        file $i | grep "exec" >/dev/null
        if [[ $? -eq 0 ]]; then
            continue
        fi
        if [[ -f $i ]]; then
            for j in `cat $i`; do
                if [[ ${#j} -gt $num ]]; then
                    if [[ $l -gt 0 ]]; then
                        if [[ ${#j} -ge ${op[$[$l-1]]} ]]; then
                            continue
                        fi
                    fi
                    num=${#j}
                    op[$l]=$num
                    str=$j
                    way=`pwd`/$i
                    nl=`cat $i | grep -n "$j" "$i" | tail -n 1 | cut -d':' -f1`
                fi
            done
        fi
    done
    cd ..
}

#now=$1
filter
for l in `seq 0 2`; do
    cd `pwd`
    long_str $l
    echo "$str $way $nl"
done
