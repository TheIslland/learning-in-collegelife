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

## ​	-b num： 字节

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



## 关于sort

[root@www ~]# sort [-fbMnrtuk][file or stdin]
选项与参数：
-f  ：忽略大小写的差异，例如 A 与 a 视为编码相同；
-b  ：忽略最前面的空格符部分；
-M  ：以月份的名字来排序，例如 JAN, DEC 等等的排序方法；
-n  ：使用『纯数字』进行排序(默认是以文字型态来排序的)；
-r  ：反向排序；
-u  ：就是 uniq ，相同的数据中，仅出现一行代表；
-t  ：分隔符，默认是用 [tab] 键来分隔；
-k  ：以那个区间 (field) 来进行排序的意思

范例一：个人账号都记录在 /etc/passwd 下，请将账号进行排序。
[root@www ~]# cat /etc/passwd | sort
adm:x:3:4:adm:/var/adm:/sbin/nologin
apache:x:48:48:Apache:/var/www:/sbin/nologin
bin:x:1:1:bin:/bin:/sbin/nologin
daemon:x:2:2:daemon:/sbin:/sbin/nologin

鸟哥省略很多的输出～由上面的数据看起来，sort 是默认『以第一个』数据来排序，

而且默认是以『文字』型态来排序的喔！所以由 a 开始排到最后啰！

范例二：/etc/passwd 内容是以 : 来分隔的，我想以第三栏来排序，该如何？
[root@www ~]# cat /etc/passwd | sort -t ':' -k 3
root:x:0:0:root:/root:/bin/bash
uucp:x:10:14:uucp:/var/spool/uucp:/sbin/nologin
operator:x:11:0:operator:/root:/sbin/nologin
bin:x:1:1:bin:/bin:/sbin/nologin
games:x:12:100:games:/usr/games:/sbin/nologin

看到特殊字体的输出部分了吧？怎么会这样排列啊？呵呵！没错啦～

如果是以文字型态来排序的话，原本就会是这样，想要使用数字排序：

cat /etc/passwd | sort -t ':' -k 3 -n

这样才行啊！用那个 -n 来告知 sort 以数字来排序啊！

范例三：利用 last ，将输出的数据仅取账号，并加以排序
[root@www ~]# last | cut -d ' ' -f1 | sort

