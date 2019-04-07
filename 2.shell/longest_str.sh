#!/bin/bash

name=0
length=0
way=0
str=0
lc=0
no_str=(0 0 0 0)
num=0

longest_str() {
    for i in `ls`; do
    if [[ -d "$i" ]]; then
        cd $i
        longest_str
        cd ..
        continue
    fi
    if [[ -f "$i" ]]; then
        for j in `strings "$i"`; do
        		max=0
            	max=${#j}
                if [[ $max -gt $maxstring ]]; then
                    if [[ $x -ne 0 ]]; then
                        maxstring2=$maxstring
                        maxstring3=$maxstring2
                        line2=$line
                        line3=$line2
                        x2=$x
                        x3=$x2
                        string2=$string
                        string3=$string2
                    fi
                    maxstring=$max
                    line=`pwd`
                    string=$j
                    x=`grep -n $j $i | tr ':' ' ' | awk '{printf $1}'`
                elif [[ $max -gt $maxstring2 && $max -lt $maxstring ]]; then
                    if [[ $x2 -ne 0 ]]; then
                        x3=$x2
                        line3=$lin2
                        maxstring3=$maxstring2
                        string3=$string2
                    fi
                    maxstring2=$max
                    line2=`pwd`
                    string2=$j
                    x2=`grep -n $j $i | tr ':' ' ' | awk '{printf $1}'`
                elif [[ $max -gt $maxstring3 && $max -lt $maxstring2 ]]; then
                    maxstring3=$max
                    line3=`pwd`
                    string3=$j
                    x3=`grep -n $j $i | tr ':' ' ' | awk '{printf $1}'`
                fi
		done
    fi
done
return
}

for x in `seq 1 3`; do 
cong=`pwd`
cd $cong
longest_str
num=$[$num+1]
no_str[$num]=$length
done;
