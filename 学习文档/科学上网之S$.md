# 科学上网之S$

因为近期河蟹严重以至于本人不得不租用vpn上p站，而在经历n次vpn暴毙而亡后。本人决定学习科学上网方法，以维护文明网络环境的方式。自古以来都有千古文章一大抄之说，在本人在经历了十个文章9个重还有8个有错误的情况后终于有幸取得真经。下面是搭建方法：

## 1.购买一个vps

这里呢，我选择购买vultr东京的线路，5$没月的套餐，一是因为2.5￥的套餐只支持IPV6，而某些辣鸡网络并不支持IPV6，所以最低的5￥套餐是很保守的选择，二是从丢包率和速度来看5￥的3%丢包率相对于2.5￥的10%丢包率来说还是相当物有所值的。系统这里我选择了centos7，（ubuntu会在之后再说）之后直接Deploy Now就可以了。稍等一会一个VPS就创建好啦

## 2.服务器端的配置

首先以为笔者是ubuntu16.04系统，之前安装过ssh，故直接`ssh root@vpsIP`就可以直接链接啦～根本不用什么辣鸡xshell，WINscp这些东西。

在经过ssh时会询问yes或者no这时候只要在命令行输入yes,之后按下回车键，然后会被询问密码，注意是vps的密码欧。在vultr中点开你创建的vps，password一行就是你的密码。

这样我们就进入了vps中开始配置vps

```shell
yum -y install vim-enhanced
```

安装一个vim方便我们更改和输入

﻿注意我们的vps系统是是CentOS 7 操作系统

第一步：安装python

```shell
yum -y install epel-release

yum -y install python-pip

yum clean all

pip install --upgrade pip

```

第二步：安装SS

```shell
pip install shadowsocks
```

第三步：配置文件路径

这里呢因为笔者的操作系统是ubuntu且安装过sshopen_server所以这里直接将文件名为

```shell
shadowsocks.json
```

的文件用`scp`命令传输到vps中，使用方法如下

```shell
scp shadowsocks.json root@vpsIP:dir
```

注意因为我的json文件在当前目录下才可直接写文件名，否则应该写全路径加文件名

下面是shadowsocks.json文件的内容

```shell
{
    "server":"0.0.0.0",
    "local_port":1080,
    "timeout": 600,
    "method":"aes-256-cfb",
    "fast_open": true,
    "port_password":
    {
        "8812": "LaoEhQcP0Zdfg17",
        "8813": "klfjee80gf00460",
        "8814": "jEhQcP0Z8lRfG28",
        "8815": "fdgrhfEdfCdf012",
        "8816": "aYWpp030gf00P0Z"     
    },
    "_comment":
    {
        "8812": "des1",
        "8813": "des2",
        "8814": "des3",
        "8815": "des4",
        "8816": "des5"    
    }
}
```

其中数字为端口名，字符串为密码。

传入后用`mv`命令移动至/etc下

第四步：自启动

首先用`cd /etc/systemd/system`移动到目标目录

之后用`touch shadowsocks.service`新建文件并用vim打开

输入下列内容

```shell
[Unit]
Description=Shadowsocks
[Service]
TimeoutStartSec=0
ExecStart=/usr/bin/ssserver -c /etc/shadowsocks.json
[Install]
WantedBy=multi-user.target

```

按`：wq`保存并推出

第五步：开机自启

在命令行输入

```shell
systemctl enable shadowsocks
```

就可以开机自动启用ss了

第六步：执行

在命令行输入前两行

```shell
systemctl start shadowsocks
systemctl status shadowsocks -l 查看状态
（systemctl stop shadowsocks） 停止运行
（systemctl restart shadowsocks） 重启(更改完端口和密码需重启生效)
```

没有ERROR一般就成功了

第七步：关闭防火墙

当防火墙开启时是没法链接的所以要关闭防火墙

```shell
查看防火墙状态：firewall-cmd --state   (running运行/notrunning未运行)
(如果为notrunning忽略一下操作)
关闭防火墙：systemctl stop firewalld.service
禁止防火墙开机启动：systemctl disable firewalld.service
查看防火墙状态：firewall-cmd --state
```

到此你就拥有了自己的科学上网工具啦~\(≧▽≦)/~

## 在centos7上用锐速加速s$

锐速是一款强大的服务器加速软件。由于这个软件只针对特定的linux内核才能使用，所以需要修改服务器系统的内核。  对于centos7，内核更换为： 3.10.0-229.1.2.el7.x86_64，在命令行中打下：

```shell
rpm -ivh http://soft.91yun.org/ISO/Linux/CentOS/kernel/kernel-3.10.0-229.1.2.el7.x86_64.rpm --force
```

安装成功后`sudo reboot`对vps进行重启后内核才能生效，**这里要注意**vps的重启是一个缓慢的过程大概要3-5分钟，请不要着急链接，这时候链接会出现错误提示或者连不上，注意这不是你vps炸了，只是需要你**等待，并心怀希望吧**3-5分钟等vps重启成功就可以连接上了。

现在开始安装锐速

```shell
wget -N --no-check-certificate https://raw.githubusercontent.com/91yun/serverspeeder/master/serverspeeder-all.sh && bash serverspeeder-all.sh
```

启用锐速

```shell
service serverSpeeder start
```

等待安装完成，那么恭喜你你拥有了自己的科学上午神器~\(≧▽≦)/~

