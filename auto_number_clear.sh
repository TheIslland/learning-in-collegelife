#!/bin/bash

dir_num=0
fil_num=0

for i in `ls`; do
    if [[ -d $1 ]]; then 
        (( dir_num=${dir_num}+1 ))
        str=`cut -d "." -f 1`
        if [[ $str == "_$dir_num" ]]; then
            name=`echo $i | awk -F "." '{ print $2 }'`
        fi
    fi
    if [[ -f $1 ]]; then 
        (( fil_num=${fil_num}+1 ))
        str=`cut -d "." -f 1`
        if [[ $str == "_$fil_num" ]]; then
            name=`echo $i | awk -F "." '{ print $2 }'`
        fi
    fi
done
