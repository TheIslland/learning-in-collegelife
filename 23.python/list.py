#!/usr/bin/env python
# coding=utf-8

#列表的声明
list = [100, 23, 45]
print list[0]
print list[1]
print list[2]
print len(list)

#列表的插入
hello = ['hi', 'hello']
world = ['earth', 'field', 'universe']
hello.append('nihao')
print hello

#列表的拼接
hello.extend(world)
print hello

#列表插入元素
hello = ['hi', 'hello']
hello.insert(0, 'nihao')
print hello
#列表内元素定位函数index（）
print hello.index('hi')

#列表的弹出与删除
hello = ['nihao', 'hi', 'hello']
#remove是将某一元素从列表中删除并且没有返回值，参数为列表中的元素值
hello.remove('nihao')
print hello
#pop是将某一元素从列表中弹出返回值为弹出元素，其参数为列表中相应元素的索引
hello.pop(0)
print hello
