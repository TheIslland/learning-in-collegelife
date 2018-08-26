#!/bin/bash
time=`date +%Y-%m-%d__%H:%M:%S`
total=`free -m | awk '{if(NR==2) printf("%s %s",$2,$3)}'`
#used=`free -m | awk '{if(NR==2) print $3}'`
(( use=${total[0]}-${total[1]}))
(( zhanyong=use*100/${total[0]} ))
echo -n "$time ${total[0]} ${total[1]} $zhanyong% "
echo "scale=1;0.3*$1+0.7$zhanyong" | bc

