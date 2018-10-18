#!/bin/bash
fil_num=0
dir_num=0
for i in `ls`; do
    if [[ $i == "a.out" ]]; then
        continue
    fi
    if [[ -d $i ]]; then
        (( dir_num=${dir_num}+1 ))
        str=`cut -d "." -f 1`
        if [[ $str == $dir_num ]]; then 
            continue
        fi
        mv $i ${dir_num}.${i}
    fi
    if [[ -f $i ]]; then
        (( fil_num=${fil_num}+1 ))
        if [[ $str == $fil_num ]]; then 
            continue
        fi
        mv $i ${fil_num}.${i}
    fi
done
