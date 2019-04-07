#!/bin/bash

num=0
str=0
the_way=0
nl=0
value=(0 0 0 0)

filter() {
    a=(rmvb png img jpg jpeg gif md avi zip tar gz 7z pb)
    suffix=`echo $1 | awk -F. '{print $NF}'`
    echo ${a[*]} | grep "$suffix" >/dev/null
    if [[ $? -eq 0 ]]; then
        return 1
    fi
    return 0
}

long_str(){
   num=0
    for i in `ls -a`; do
        if [[ $i == "." || $i == ".." ]]; then
            continue
        fi
        file $i | grep "exec" >/dev/null
        if [[ $? -eq 0 ]]; then
            continue
        fi
        filter $i
        if [[ $? -eq 1 ]]; then
            continue 
        fi
        if [[ -d $i ]]; then
            cd $i
            long_str
            cd ..
            continue
        fi
        if [[ -f $i ]]; then
            for j in `cat $i`; do
                if [[ ${#j} -gt $num ]]; then
                    if [[ $l -gt 0 ]]; then
                        if [[ ${#j} -ge ${value[$[$l-1]]} ]]; then
                            continue
                        fi
                    fi
                    num=${#j}
                    value[$l]=$num
                    str=$j
                    the_way=`pwd`/$i
                    nl=`grep -n "$j" "$i" | awk -F":" '{if (NR==1) print $1}'`
                fi
            done
        fi
    done
    cd ..
}

now=$1
filter
for l in `seq 0 2`; do
    cd $1
    long_str $l
    echo "${value[$l]}:$str:$the_way:$nl"
done
