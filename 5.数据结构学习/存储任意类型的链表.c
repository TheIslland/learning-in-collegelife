/*************************************************************************
	> File Name: 存储任意类型的链表.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年02月22日 星期五 10时10分19秒
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef __compiler_offsetof
#define offsetof(TYPE, MEMBER) __compiler_offsetof(TYPE, MEMBER)
#else
#define offsetof(TYPE, MEMBER) ((size_t) & ((TYPE *)0)->MEMBER) //由于地址从零开始，转化为ｔｙｐｅ型后取成员变量的首地址转化为整形后相当于知道了结构体非公用部分的字节数
#endif

/*offsetof宏的作用是计算结构体字节数
    type指类型 0是指向一个空地址 member 是成员变量　ptr　指任意类型链表公用连接结构
    container_of第二行的作用是声明一个指向type类型中member成员变量的类型的执政__mptr用于存储ptr公用连接结构
    第三行通过转化为ｃｈａｒ型地址用公用连接结构首地址减去非公用连接结构字节数得到结构体首地址
*/
#define container_of(ptr, type, member) ({ \
	const typeof( ((type *)0)->member) *__mptr = (ptr);\
    printf("%lu\n", offsetof(type, member));\
	(type *)( (char *)__mptr - offsetof(type, member));})

struct head_list {
    struct head_lsit *next;
    struct head_lsit *prev;
};

struct test_struct {
    int num;
    char ch;
    float fl;
    double d1;
    double b2;
    struct head_list list;
};

struct test_struct2 {
    int dobule;
    struct head_list list;
};

int main() {
    struct test_struct init_struct = { 20, 'C', 59.12, 123.23, 234.56, NULL};
    struct test_struct *test_struct = container_of(&init_struct.list, struct test_struct, list);
    printf(" test_struct->num = %d\n test_struct->ch = %c\n test_struct->fl = %f\n", test_struct->num, test_struct->ch, test_struct->fl);
    return 0;
}
