#!/bin/bash
yum -y install vim-enhanced
yum -y install epel-release
yum -y install python-pip
yum clean all
pip install --upgrade pip
pip install shadowsocks
wget https://raw.githubusercontent.com/TheIslland/learning-in-collegelife/master/2.shell/shadowsocks.json
mv shadowsocks.json /etc
wget https://raw.githubusercontent.com/TheIslland/learning-in-collegelife/master/2.shell/shadowsocks.service
chmod a+x shadowsocks.service
mv shadowsocks.service /etc/systemd/system
systemctl enable shadowsocks
systemctl start shadowsocks
systemctl status shadowsocks -l
firewall-cmd --state 
systemctl stop firewalld.service
systemctl disable firewalld.service
firewall-cmd --state

