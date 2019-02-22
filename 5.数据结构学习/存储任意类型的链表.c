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
#define offsetof(TYPE, MEMBER) ((size_t) & ((TYPE *)0)->MEMBER) //返回成员的地址 和偏移量相似
#endif

//type类型 0值空地址 member 把某个字段的地址赋值给相应的指针类型 
//mptr指向list位置地址  得到相关变量的首地址 
#define container_of(ptr, type, member) ({ \
	const typeof( ((type *)0)->member) *__mptr = (ptr);\
	(type *)( (char *)__mptr - offsetof(type, member));})

struct head_list {
    struct head_lsit *next;
    struct head_lsit *prev;
};

struct test_struct {
    int num;
    char ch;
    float fl;
    struct head_list list;
};

struct test_struct2 {
    int dobule;
    struct head_list list;
};

int main() {
    struct test_struct init_struct = { 20, 'C', 59.12, NULL};
    struct test_struct *test_struct = container_of(&init_struct.list, struct test_struct, list);
    printf(" test_struct->num = %d\n test_struct->ch = %c\n test_struct->fl = %f\n", test_struct->num, test_struct->ch, test_struct->fl);
    return 0;
}
