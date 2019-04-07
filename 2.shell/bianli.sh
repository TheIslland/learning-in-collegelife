#!/bin/bash
num_d=0
num_f=0
find() {
for i in `ls -a`; do
    if [ -d "$i" ] 
    then
        if [ $i == '.' ] || [ $i == '..' ]
        then
            continue
        fi
        (( num_d+=1 ));
        cd $i
        find
        cd ..
        continue
    fi
    if [ -f "$i" ]
    then
        (( num_f+=1 ));
    fi
done
}
cd $1
find
echo $num_d
echo $num_f

