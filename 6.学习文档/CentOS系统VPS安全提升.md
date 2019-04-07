# CentOS系统VPS安全提升

本文所有代码基于CentOS 6.4操作系统为例进行说明，于6.x版本应该都是适用的，其他版本的话主要是命令的路径不同，思路是一致的。本文也可以称为：CentOS操作系统全设置与优化。安装好CentOS系统后，建议不要急着去做这些安装设置和优化，因为过早操作，会在Web环境搭建（特别是用主机控制面板的）过程当中因为早过禁止某些权限和程序而造成问题。所以这些安全设置和优化，建议最后才来操作。

第一步、账户安全管理

 

\1. 修改密码长度 

 vi /etc/login.defs

 

PASS_MIN_LEN 18

 

\2. 创建一个普通用户账号并设置密码，这样所有的操作都使用该普通账号进行，后面还要禁止Root帐号的操作。

 

 

 

 useradd ru

 

 passwd ru

 

上面的ru用你想创建的用户名替代

 

 

\3. 禁用不必要的帐号

 

 

Linux默认提供了很多账号，账号越多，系统就越容易受到攻击，所以应该禁止所有默认的被操作系统本身启动的并且不必要的账号。 可以使用 vi /etc/passwd 查看系统账号，使用 vi /etc/group 查看系统的用户组。

 

 

 userdel adm

 

 userdel lp

 

 userdel sync

 

 userdel shutdown

 

 userdel halt

 

 userdel news

 

 userdel uucp

 

 userdel operator

 

 userdel games

 

 userdel gopher

 

 userdel ftp

 

 

 

 groupdel adm

 

 groupdel lp

 

 groupdel news

 

 groupdel uucp

 

 groupdel games

 

 groupdel dip

 

 groupdel pppusers

 

以上代码一条一条输入运行既可。

 

 

 

\5. 禁止非授权用户获得权限

 

 

 chattr +i /etc/passwd

 

 chattr +i /etc/shadow

 

 chattr +i /etc/group

 

 chattr +i /etc/gshadow

 

这样操作之后也无法创建账号和修改密码，后面可以使用chattr -i命令恢复之后再进行操作。这也是为什么本人文章开始时建议大家搭建VPS时最后做这些优化了。

 

\6. 禁止Ctrl+Alt+Delete重启命令

修改 /etc/inittab 文件，将下面一行注释掉

 

ca::ctrlaltdel:/sbin/shutdown -t3 -r now

 

或者

 

 

[root@localhost ~]# vi /etc/init/control-alt-delete.conf 

 

\#exec /sbin/shutdown -r now "Control-Alt-Deletepressed"  #注释掉

\7. 设置/etc/profile

 

 

 

\# 设置自动退出终端，防止非法关闭ssh客户端造成登录进程过多，可以设置大一些，单位为秒

 

 echo "TMOUT=3600" >>/etc/profile

 

\# 历史命令记录数量设置为10条

 

 sed -i "s/HISTSIZE=1000/HISTSIZE=10/" /etc/profile

 

 source /etc/profile

\8. 重新设置 /etc/rc.d/init.d/ 目录下所有文件的许可权限

 

/etc/rc.d/init.d/ 目录下所有文件仅root账号可以读、写和执行其中的所有脚本文件：

 

 chmod -R 700 /etc/rc.d/init.d/*

 

第二步、SSH安全配置

 

SSH作为系统登录的入口，其安全性的重要性不言而喻。一般系统都会默认安装了SSH。如果没有安装SSH，使用yum install ssh命令进行安装。

 

 

接下来先备份原来的配置文件

 

 

 cp /etc/ssh/sshd_config /etc/ssh/sshd_config.bak

 

然后修改 Vi /etc/ssh/sshd_config 文件：

 

 

\#SSH的端口，默认为22，比喻改为5028端口

 

Port 5028

 

\# 将#protocol 2,1改为

 

protocol 2

 

\# 不允许root用户直接登录

 

PermitRootLogin no

 

\# 不允许空密码登录

 

PermitEmptyPasswords no

 

\# 不允许使用网址登录

 

UseDns no

 

然后使用 service sshd restart 重启SSH服务。

 

 

 

第三步、关闭系统中不需要的服务，删除不必要的软件包

 

\1. 删除不必要的软件包

 

 

yum remove Deployment_Guide-en-US finger cups-libs cups ypbind

 

yum remove bluez-libs desktop-file-utils ppp rp-pppoe wireless-tools irda-utils

 

yum remove sendmail* samba* talk-server finger-server bind* xinetd

 

yum remove nfs-utils nfs-utils-lib rdate fetchmail eject ksh mkbootdisk mtools

 

yum remove syslinux tcsh startup-notification talk apmd rmt dump setserial portmap yp-tools

 

yum groupremove "Mail Server" "Games and Entertainment" "X Window System" "X Software Development"

 

yum groupremove "Development Libraries" "Dialup Networking Support"

 

yum groupremove "Games and Entertainment" "Sound and Video" "Graphics" "Editors"

 

yum groupremove "Text-based Internet" "GNOME Desktop Environment" "GNOME Software Development"

\2. 关闭不必要的服务

 

 

命令：chkconfig 服务内容 off

 

 

输入以下命令，禁止相应服务：

 

 

\#linux新型电源管理标准，建议笔记本使用  

 

chkconfig acpid off  

 

\#和 cron 相似的任务调度器，只不过它并不要求系统持续运行  

 

chkconfig anacron off  

 

\#运行用户用at命令调度的任务，需要用到at的得留着  

 

chkconfig atd off  

 

\#蓝牙的，没有就关了  

 

chkconfig bluetooth off  

 

\#不做打印服务器的就关了吧  

 

chkconfig cups off  

 

\#系统安装后第一次启动的配置工具  

 

chkconfig firstboot off  

 

\#蓝牙的输入支持  

 

chkconfig hidd off  

 

\#ipv6防火墙  

 

chkconfig ip6tables off  

 

\#内网的话就懒得配置防火墙了  

 

chkconfig iptables off  

 

\#新增硬件检测  

 

chkconfig kudzu off  

 

\#主要用于SELinux，不开SELinux的话就关了  

 

chkconfig mcstrans off  

 

\#IA32微码驱动程序  

 

chkconfig microcode_ctl off  

 

\#SELinux用于监控文件  

 

chkconfig restorecond off  

 

\#邮件程序，如果不是邮件服务器就关了  

 

chkconfig sendmail off  

 

SELinux Troubleshooting  

 

chkconfig setroubleshoot off  

 

\#禁止系统自动更新  

 

chkconfig yum-updatesd off  

 

然后重启服务器 reboot 开机就不会启动这些服务了

 

 

 

 

 

第四步、防止攻击

 

\1. 阻止ping

 

 

将 /proc/sys/net/ipv4/icmp_echo_ignore_all 文件的内容修改为1，不过这样的话如果服务器重启之后就会恢复为0了。

 

 

可以将下面的内容加入到 /etc/rc.d/rc.local 文件中：

 

 

echo 1 /proc/sys/net/ipv4/icmp_echo_ignore_all

\2. 防止IP欺骗攻击

 

 

编辑 /etc/host.conf 文件，在下面增加如下几行：

 

 

 vi /etc/host.conf

 

order bind，hosts

 

multi off

 

nospoof on

 

\3. 防止DoS攻击

 

 

对系统所有的用户设置资源限制可以防止DoS类型攻击。如最大进程数和内存使用数量等。对 /etc/security/limits.conf 文件添加如下内容：

 

 

\# 禁止调试文件

 

\* hard core 0

 

\# 限制内存使用为5MB

 

\* hard rss 5000

 

\# 限制进程数为20

 

\* hard nproc 20

 

* 

 

接下来必须编辑 /etc/pam.d/login 文件确认下面一行是否存在，如果不存在的话添加上：

 

 

 

 

 

session required /lib/security/pam_limits.so

 

对于DDos攻击可以使用DDoS deflate脚本，详细介绍见下面的参考资料。

 

 

 

 

 

第五步、系统配置及性能调优

 

\1. 修改系统默认字符集

 

 

 

 

 

如果使用英文安装系统之后，如果系统中有中文会显示乱码，这个时候需要修改系统默认的字符集：

 

 

 

 

 

 

 

 vi /etc/sysconfig/i18n

 

LANG="zh_CN.UTF-8"

 

 ##Vi编辑器常用命令`i`为修改，`Esc`为退出编辑状态，`:wq`为保存退出

 

 source /etc/sysconfig/i18n

 

将系统的编码修改为zh_CN.UTF-8，后面一句命令是让修改立即生效。

 

 

 

 

 

** 2. 使用ntp服务更新服务器时间**

 

 

 

 

 

首先检查系统中是否安装了ntp服务：

 

 

 

 

 

 chkconfig --list |grep ntp

 

如果没有安装的话使用yum进行安装并更新时间

 

 

 

 

 

 

 

 yum install ntp

 

 ntpdate time.windows.com

 

也可以将更新命令加入到cron中进行自动更新时间：

 

 

 

 

 

 

 

 crontab -e

 

\* */12 * * * ntpdate time.windows.com

 

 

 

 service crond restart

 

以上操作是每隔12小时自动更新一次时间，可以通过 crontab -l 命令进行查看。

 

 

 

 

 

** 3. 去掉系统相关信息**

 

 

 

 

 

[root@localhost ~]# echo "Welcome to Server" >/etc/issue 

 

[root@localhost ~]# echo "Welcome to Server" >/etc/redhat-release 

 

** 4. 同步系统时间**

 

 

 

 

 

[root@localhost ~]# cp /usr/share/zoneinfo/Asia/Shanghai/etc/localtime  #设置Shanghai时区 

 

[root@localhost ~]# ntpdate cn.pool.ntp.org ；hwclock–w  #同步时间并写入blos硬件时间 

 

[root@localhost ~]# crontab –e #设置任务计划每天零点同步一次 

 

0 * * * * /usr/sbin/ntpdate cn.pool.ntp.org ; hwclock -w 

 

** 5. 系统内核优化**

 

 

 

 

 

 

 

[root@localhost ~]# vi /etc/sysctl.conf #末尾添加如下参数 

 

net.ipv4.tcp_syncookies = 1 #1是开启SYN Cookies，当出现SYN等待队列溢出时，启用Cookies来处，理，可防范少量SYN攻击，默认是0关闭 

 

net.ipv4.tcp_tw_reuse = 1 #1是开启重用，允许讲TIME_AIT sockets重新用于新的TCP连接，默认是0关闭 

 

net.ipv4.tcp_tw_recycle = 1 #TCP失败重传次数，默认是15，减少次数可释放内核资源 

 

net.ipv4.ip_local_port_range = 4096 65000  #应用程序可使用的端口范围 

 

net.ipv4.tcp_max_tw_buckets = 5000 #系统同时保持TIME_WAIT套接字的最大数量，如果超出这个数字，TIME_WATI套接字将立刻被清除并打印警告信息，默认180000

 

net.ipv4.tcp_max_syn_backlog = 4096 #进入SYN宝的最大请求队列，默认是1024

 

net.core.netdev_max_backlog =  10240  #允许送到队列的数据包最大设备队列，默认300

 

net.core.somaxconn = 2048  #listen挂起请求的最大数量，默认128

 

net.core.wmem_default = 8388608 #发送缓存区大小的缺省值 

 

net.core.rmem_default = 8388608 #接受套接字缓冲区大小的缺省值（以字节为单位） 

 

net.core.rmem_max = 16777216   #最大接收缓冲区大小的最大值 

 

net.core.wmem_max = 16777216   #发送缓冲区大小的最大值 

 

net.ipv4.tcp_synack_retries = 2  #SYN-ACK握手状态重试次数，默认5

 

net.ipv4.tcp_syn_retries = 2   #向外SYN握手重试次数，默认4

 

net.ipv4.tcp_tw_recycle = 1  #开启TCP连接中TIME_WAIT sockets的快速回收，默认是0关闭 

 

net.ipv4.tcp_max_orphans = 3276800  #系统中最多有多少个TCP套接字不被关联到任何一个用户文件句柄上，如果超出这个数字，孤儿连接将立即复位并打印警告信息 

 

net.ipv4.tcp_mem = 94500000 915000000 927000000

 

net.ipv4.tcp_mem[0]:低于此值，TCP没有内存压力； 

 

net.ipv4.tcp_mem[1]:在此值下，进入内存压力阶段； 

 

net.ipv4.tcp_mem[2]:高于此值，TCP拒绝分配socket。内存单位是页，可根据物理内存大小进行调整，如果内存足够大的话，可适当往上调。上述内存单位是页，而不是字节。 

 

或者用以下参数进行优化

 

 

 

 

 

 cp /etc/sysctl.conf /etc/sysctl.conf.bak  vi /etc/sysctl.conf

 

 

 

 

 

net.ipv4.tcp_fin_timeout = 2

 

net.ipv4.tcp_tw_reuse = 1

 

net.ipv4.tcp_tw_recycle = 1

 

net.ipv4.tcp_syncookies = 1

 

net.ipv4.tcp_keepalive_time = 600

 

net.ipv4.ip_local_port_range = 400065000

 

net.ipv4.tcp_max_syn_backlog = 16384

 

net.ipv4.tcp_max_tw_buckets = 36000

 

net.ipv4.route.gc_timeout = 100

 

net.ipv4.tcp_syn_retries = 1

 

net.ipv4.tcp_synack_retries = 1

 

net.ipv4.ip_conntrack_max = 25000000

 

net.ipv4.netfilter.ip_conntrack_max=25000000

 

net.ipv4.netfilter.ip_conntrack_tcp_timeout_established=180

 

net.ipv4.netfilter.ip_conntrack_tcp_timeout_time_wait=120

 

net.ipv4.netfilter.ip_conntrack_tcp_timeout_close_wait=60

 

net.ipv4.netfilter.ip_conntrack_tcp_timeout_fin_wait=120

 

最后，使用 sysctl –p 命令让上述设置立即生效。最后都设置好后，记得禁止系统自动更新，同时自已建立一个系统镜像吧，到时需要时就恢复回去，不必要每装一次系统就重复设置一次。