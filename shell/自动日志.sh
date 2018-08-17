#!/bin/bash
source .back.rc
if [[ ! -d $dest_dir ]]; then
    echo -e "\033[33m $time_now 【ERROR】the Dest dir $dest_dir not exists \033[0m" >> ~/learning-in-collegelife/log
    return
fi
time_now="`date +%Y-%m-%d,%H:%m`"
echo -e "\033[33m $time_now backup is start \033[0m" >> ~/learning-in-collegelife/log 
for i in `echo $backup_path | tr ":" "\n"`;do
    if [[ ! -d $i ]]; then
        echo -e "\033[33m $time_now backup 【ERROR】the dir $i not exists \033[0m" >> ~/learning-in-collegelife/log
    continue
    fi
    cd $i
    time_now="`date +%Y-%m-%d,%H:%m`"
    way=`pwd`
    echo -n -e "\033[33m $time_now backup $way \033[0m" >> ~/learning-in-collegelife/log
    n=0
    for k in `du -sh $way`; do
        (( n+=1 ))
        if [ $n -ne 1 ]
        then
            break
        fi
        echo -e $k >> ~/learning-in-collegelife/log
    done
    target=`echo $i | cut -d "/" -f 2 | tr "/" "_"`
    target=${target}_${time_now}
    tar -czPf /home/mason/learning-in-collegelife/shell/save/${target}.tar.gz $i
    echo -e -n "\033[33m $time_now delete $way --> ${target}.tar.gz \033[0m" >> ~/learning-in-collegelife/log
    n=0
    for h in `du -sh $way`; do
        (( n+=1 ))
        if [ $n -ne 1 ]
        then
            break
        fi
        echo $h >> ~/learning-in-collegelife/log
    done   
    cd ..
done
	Del_list=`find $dest_dir -name "*.tar.gz" -mtime +3`
	for i in $Del_list; do
	rm -f $i
    	echo -e "\033[33m $time_now delete $i --> remove -${h} \033[0m" >> ~/learning-in-collegelife/log
	done 
