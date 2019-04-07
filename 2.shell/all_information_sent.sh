#!/bin/bash

read code
for i in `w -h | awk '{ print $1 }'`; do

    echo "`whoami`" >> /dev/$i
    echo $1 >> /dev/$i
done
