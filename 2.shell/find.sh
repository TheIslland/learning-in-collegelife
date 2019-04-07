#!/bin/bash

num=0
ans=0
temp=0
length=0
echo `ls` >> touch

for i in `strings touch`; do 
	for j in `strings $i`; do 
		mid=0
		mid=${#j}
		if [[ mid -gt temp ]]; then
            length=$mid
           # temp=$j
        fi
	done
done
echo $temp
echo $length
`rm touch`

