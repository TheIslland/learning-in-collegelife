#!/bin/bash
a=0
b=0
maxstring=0
line=0
string=0
x=0
string2=0;
x2=0
string3=0
line2=0
x3=0
line3=0
ans=0
maxstring2=0
maxstring3=0

find() {
    for i in `ls`; do
        if [[ ! -r "$i" ]]; then
            continue
        fi
        if [[ $i == "." || $i == ".." ]]; then
            continue
        elif [[ -f "$i" ]]; then
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
        elif [[ -d "$i" ]]; then
            cd $i
            find;
            cd ..
        fi
    done
}

cd `pwd`
find
echo "$string $x  $line"
echo "$string2 $x2 $line2"
echo "$string3 $x3 $line3"
