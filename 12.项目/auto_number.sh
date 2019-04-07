#!/bin/bash
fil_num=1
dir_num=1
for i in `ls`; do
    if [[ $i == "a.out" ]]; then
        continue
    fi
    if [[ -d $i ]]; then
       mv $i ${dir_num}.${i}
       (( dir_num=${dir_num}+1 ))
    fi
    #if [[ -f $i ]]; then
    #    mv $i ${fil_num}.${i}
    #    (( fil_num=${fil_num}+1 ))
   # fi
done
