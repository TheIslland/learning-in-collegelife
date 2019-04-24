#coding=utf-8
#find函数
weather = 'rainy day'
bag = 'nothing in the bag'
if weather.find('rain') != -1:
	#find函数会在原字符串中查找参数传入的子字符串，如果没有找到请求会返回-1否则返回索引位置
    #replace函数会将原字符串替换为第二参数的字符串
    bag = bag.replace('nothing', 'umbrella')
    
print bag

#格式化输出
#coding=utf-8
name = 'Wangmu Niangniang'
age = 9000
height = 1.73
print name + ' is a ' + str(age) + '-year-old woman with height ' + str(height)
#格式化输出在单引号外的%前定义了输出字符串的格式，其中的%s表示字符串变量潜入占位，%d表示整数变量嵌入
print '%s is a %d-year-old woman with height %g' % (name, age, height)

#u的作用
#u的作用是将一个字符串转化为unicode编码
s = u'I want to say \u4e2d\u56fd\u4e07\u5c81'
s = s.encode('utf-8')
print s

#批量替换
 str = raw_input().replace(' ', r'%20')
