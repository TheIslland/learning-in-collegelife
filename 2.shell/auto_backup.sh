#!/bin/bash

source ~/project_backup/.backup.rc #配置文件 .backup.rc里定义了文件路径
TIME_NOW=`date +"%Y-%m-%d %H:%M"` # 现在的时间
TIME_FILE=`date +"%Y_%m_%d_%H_%M"` # 文件的时间

# dest_dir=~/project_backup/backup 备份路径
# back_dir=$1
# log=~/project_backup/backup.log 日志文件路径

if [[ ! -d $dest_dir ]]; then # 如果备份目录不是目录则报错
    echo "$TIME_NOW [ERROR] The Dest dir $dest_dir not exists" >> $log # 记录日志
    exit
fi

echo "$TIME_NOW backup started!" >> $log # 开始进行打包并记录日志

for i in `echo $back_dir | tr ":" "\n"`; do # 遍历需要打包的目录
    if [[ ! -d $i ]]; then # 如果不是目录报错
        echo "%TIME_NOW backup [ERROR] The dir $i not exists" >> $log
    fi
    echo "$i started"
    target=`echo $i | cut -d "/" -f 2- | tr "/" "_"` # 提取文件名
    target=${target}_${TIME_FILE}.tar.gz # 进行压缩包命名
    tar czPf "${dest_dir}/${target}" $i # 进行打包
    if [[ $? -eq 0 ]]; then # 判断打包是否成功
        for i in `du -h ${dest_dir}/${target}`; do # 记录压缩包占用空间大小
            size=$i
            break
        done
        echo -e "\033[47;34m $TIME_NOW backup $i --> $target +${size} \033[0m" >> $log
    else
        echo "$TIME_NOW [ERROR] Something ..." >> $log
    fi
done

Del_list=`find $dest_dir -name "*.tar.gz" -mtime +3` # 找到三天前的压缩包

for i in $Del_list; do # 删除三天前的压缩包
    for j in `du -h $i`; do
        size=$j
        break
    done
    echo -e "\033[47;34m $TIME_NOW delete $i --> remove -${size} \033[0m" >> $log
    rm -f $i
done
