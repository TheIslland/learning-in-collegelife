#!/bin/bash

#给当前目录下的文件和目录标号

for i in `ls | sort -n -r`; do
    if [[ $i == "a.out" ]]; then
        continue
    fi
    if [[ -f $i || -d $i ]]; then
        str=`echo "$i" | cut -d"." -f1 | grep -v "[a-z][A-Z]" | grep "[0-9]"`
        if [[ $str > 0 ]]; then
            str=`echo "$i" | cut -d"." -f2-`
            mv "$i" "$str"
        fi
    fi
done
