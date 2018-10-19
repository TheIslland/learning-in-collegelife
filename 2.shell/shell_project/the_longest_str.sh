#!/bin/bash
old=${IFS}
IFS=$'\n'
num=0
str=0
way=0
nl=0
op=(0 0 0 0)

#filter() {
#    a=(rmvb png img jpg jpeg gif md avi zip tar gz 7z)
#    suffix=`echo $1 | awk -F. '{print $NF}'`
#    echo ${a[*]} | grep "$suffix" >/dev/null
#    if [[ $? -eq 0 ]]; then
#        return 1
#    fi
#    return 0
#}

long_str(){
    for i in `ls -A `; do
        #file $i | grep "exec" >/dev/null
        #if [[ $? -eq 0 ]]; then
        #    continue
       # fi
       # filter $i
       # if [[ $? -eq 1 ]]; then
        #    continue 
        #fi
		if [[ $i == ".ssh" || $i == ".bashrc" || $i == "str1.sh" ]]; then
			continue
		fi
		if [[ -d "$i" ]]; then
            cd "$i"
            long_str
            cd ..
            continue
        fi
        if [[ -f "$i" ]]; then
			IFS=$old
            for j in `strings "$i"`; do
			#	echo "$j ${#j} ? $num"
		#	judg=`echo $j | grep [\]`
			#if [ -n "$judg" ]; then
		#		echo "qwe">/dev/null
	#		else 
	#			continue
	#		fi
                if [[ ${#j} -gt $num ]]; then
                    if [[ $l -gt 0 ]]; then
                        if [[ ${#j} -ge ${op[$[$l-1]]} ]]; then
                            continue
                        fi
                    fi
                    num=${#j}
                    op[$l]=$num
                    str=$j
                    way=`pwd`/$i
                    #nl=`grep -n $j $i 2>/dev/null | tr ':' ' ' | awk '{printf $1}'`
					nl=`grep -n "$j" "$i" | awk -F":" '{if (NR==1) print $1}'`
                fi
            done
			IFS=$'\n'
        fi
    done
   # cd ..
}

now=`pwd`
#filter
echo "#Problem 1" #>> ~/.score.txt
for l in `seq 0 2`; do
    cd $now
    long_str $l
    echo -e "${op[$l]}:${str}\t:${way}\tLine:${nl}" # >> ~/.score.txt
	num=0
done
