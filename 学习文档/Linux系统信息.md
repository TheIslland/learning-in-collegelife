# Linux系统信息

## UPYIME系统运行时长，平均负载

语法：

`uptime [phsv]`

例:`uptime -p`,`uptime -s`

## w获取当前分登录用户和正在执行的进程

语法：

`w [husfV] <user> <...>`

options:

​	h:不打印头信息

​	s:使用短输出格式

​	f:切换显示FROM项，默认显示

## WHO显示当前登录系统的用户信息

语法：

`who [option] <file | arg1 arg2> `

选项：

​	-H:显示各栏的标题信息列

​	-u:显示空置时间

​	-q:只显示登入系统的用户名称和总人数

例：`who -H`,`who -q` ,`who -a`

## WHOAMI打印当前有效的用户名称

语法：

`whoami`

例：`whoami`,`id -un`,`id root`

## LAST显示用户最近登录信息

语法：

`last [fnx] <username...> <tty...>`

选项：

​	-f "file":制定记录文件

​	-n "num":指定输出记录数

​	-x:显示系统关机，重新关机等信息

`last -x -n 10`

## UNAME打印当前系统信息

语法：

`uname [options]`

参数：

​	-a：全部信息

​	-m：电脑类型

​	-n：网络上主机的名称

​	-v:os版本

​	-p：处理器类型

​	-i：硬件平台

​	-o：操作系统名称

## date显示或设置系统时间与日期

语法：

`date [dsu] <参数>`

选项

​	-d "string":显示字符串所指的日期

​	-s "string":设置时间

​	-u:显示GMT（）

## cal日历