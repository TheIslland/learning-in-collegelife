# Linux数据提取操作

## TR对标准输入的字符替换，压缩，删除

`tr [csdt] <字符集> <字符集>`

​	c取代所有不属于第一字符集的字符

​	d删除所有属于第一字符集的字符

​	s将连续重复的字符以单独一个字符表示

​	t先删除第一字符集较第二字符集多出的字符

## cut切分

​	-d c：以c字符分割

​	-f num：显示num字段的内容

​	-b num： 字节

​	-c num： 字符

## GREP检索

`grep [-acinv] <string> <file>`

​	-a: 将二进制文件以普通文件的形式搜索数据

​	-c：统计搜寻到的次数

​	-i：忽略大小写

​	-n：顺序输出行号

​	-v：反向输出

## SORT排序

`sort [-fbMnrtuk] <sile_or_stdio>`

​	-f：忽略大小写

​	-b：忽略最前面的空格

​	-M：以月份名称排序

​	-n：以纯数字方式排序

​	-r：反向排序

​	-u：uniq

​	-t：分割符，默认[TAB]

​	-k：以那个区间排序

## WC统计字符，字数，行数

`wc [-lwm] <file_or_stdin>`

​	-l:仅列出行号

​	-w：仅列出多少字

​	-m：仅列出多少字符

## UNIQ

`uniq [-ic]`

​	-i：忽略大小写字符的不同

​	-c：进行计数

## TEE双向重导项

`tee [-a] file`

​	-a：append

## SPLIT文件切分

`split [-bl] <file> PREFIX`

​	-b SIZE：且分为SIZE大小的文件

​	-l num：以num行为大小切分

## XARGS参数代换

`xargs [-0pne] <command>`

​	-0：将特殊字符还原为普通字符

​	-eEOF：当xargs读到EOF时停止

​	-p：执行指令前询问

​	-n num：每次执行command时需要的参数个数



