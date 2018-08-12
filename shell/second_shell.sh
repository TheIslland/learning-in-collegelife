#!/bin/bash
echo "hellow"
echo "world"
a=12
echo $a
echo $0
echo $1
echo $*
echo $#
for i in "$*";do
    echo $i
done
