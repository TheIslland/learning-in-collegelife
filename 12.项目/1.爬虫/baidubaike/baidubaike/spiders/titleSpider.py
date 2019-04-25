# -*- coding: utf-8 -*-
import scrapy
from scrapy import Request
from fake_useragent import UserAgent

class TitlespiderSpider(scrapy.Spider):
    name = 'titleSpider'
    allowed_domains = ['baidu.com']
    base_url = "https://baike.baidu.com"
    start_url = 'https://baike.baidu.com/item/%E6%96%90%E6%B3%A2%E9%82%A3%E5%A5%91%E6%95%B0%E5%88%97/99145?fr=aladdin'
    filename = "output"
    #python中self类似于c++中的this，self指向当前对象本身
    def __init__(self):
        self.agent = UserAgent()
        self.fout = open(self.filename, "wb+")
        #在python3.7中w     以写方式打开，
	#a     以追加模式打开 (从 EOF 开始, 必要时创建新文件)
	#r+     以读写模式打开
	#w+     以读写模式打开 (参见 w )
	#a+     以读写模式打开 (参见 a )
	#rb     以二进制读模式打开
	#wb     以二进制写模式打开 (参见 w )
	#ab     以二进制追加模式打开 (参见 a )
	#rb+    以二进制读写模式打开 (参见 r+ )
	#wb+    以二进制读写模式打开 (参见 w+ )
	#ab+    以二进制读写模式打开 (参见 a+ )

    def start_requests(self):
	yield Request(url = self.start_url, meta = {"level" : 1, "raw_title" : ""}, callback = self.parse)
	#带有yield的函数相当于一个发生器，执行到yeild会直接终端程序并返回yield语句的值
	#用requese获取网页内容，从url获取网页内容并且初始化字典meta，并调用parse函数获取返回值给callback

    def parse(self, response):
	#选区所有h1标签下的文本无论h1在任何地方
        h1_list = response.xpath("//h1/text()")
	#更行字典内raw—title的内容并加上获取的内容
        data = response.meta["raw_title"] + h1_list[0].extract()
        self.fout.write(data.encode("UTF8"))
        data2 = '\n'
        self.fout.write(data2.encode("UTF8"))
        data += ' -> '
	#向下递归爬取5层
        if response.meta["level"] < 5:
            ahref_list = response.xpath("//div[@class='lemma-summary']/div[@class='para']/a/@href")
            for link in ahref_list:
                url = self.base_url + link.extract()
                yield Request(url = url, meta = {"level" : response.meta["level"] + 1, "raw_title" : data}, callback = self.parse)

