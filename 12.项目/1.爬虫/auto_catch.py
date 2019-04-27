#!/usr/bin/env python
# coding=utf-8

from selenium import webdriver

browser = webdriver.Chrome()
browser.get("https://www.baidu.com")

fin = open("./cookie_file", "r")
for line in fin:
    name, value, domain = line.strip().split("\t")
    #d = {"name" : name, "value" : value, "domain" : domain}
    #browser.add_cookie(d)

browser.get("https://www.jisuanke.com")
