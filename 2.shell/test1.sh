#!/bin/bash
echo $1
echo $#
echo $0
echo $?
v1="just for"
v2="fun"
v3=${v1}${v2}
echo $v3
a=1
b=2
let c=$a+$b
echo $c
(( d=a+b ));
echo $d
echo $a+$b | bc
if [ -f ~/learning-in-collegelife/shell/test1.sh ]
then
    echo "File exists"
fi
num=(1 2 3 5)
echo ${#num[@]}
unset num[2]
echo ${num[*]}
string1="qwertyuiopasf"
echo ${string1:3:2}
string2="user :123 :321: /home/dir"
echo $string2|tr -d " "
echo ${string2:5}
echo ${string2:-5}
set ${string2}
echo $#
export string1
echo $string2 | cut -d " " -f 4 | tr "/" "_"

