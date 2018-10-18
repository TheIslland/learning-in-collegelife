#!/bin/bash

dir_num=0
fil_num=0

for i in `ls`; do
    if [[ -d $i ]]; then 
        (( dir_num=${dir_num}+1 ))
        str=`echo $i | cut -d "." -f 1`
        if [[ $str == "_$dir_num" ]]; then
            name=`echo $i | awk -F "." '{ print $2 }'`
            mv $i $name
        fi
    fi
    if [[ -f $i ]]; then 
        (( fil_num=${fil_num}+1 ))
        str=`echo $i | cut -d "." -f 1`
        if [[ $str=="_$fil_num" ]]; then
            name=`echo $i | awk -F "." '{ print $2 }'`
            mv $i $name
        fi
    fi
done
