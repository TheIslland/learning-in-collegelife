#!/bin/bash
yum -y install vim-enhanced
yum -y install epel-release
yum -y install python-pip
yum clean all
pip -y install --upgrade pip
pip -y install shadowsocks
wget -c https://raw.githubusercontent.com/TheIslland/learning-in-collegelife/master/shell/shdowsocks.json
mv shdowsocks.json /etc
wget -c https://raw.githubusercontent.com/TheIslland/learning-in-collegelife/master/shell/shadowsocks.service
mv shadowsocks.service /etc/systemd/system
systemctl enable shadowsocks
systemctl start shadowsocks
systemctl status shadowsocks -l
firewall-cmd --state 
systemctl stop firewalld.service
systemctl disable firewalld.service
firewall-cmd --state

