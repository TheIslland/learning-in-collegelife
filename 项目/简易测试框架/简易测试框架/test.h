/*************************************************************************
	> File Name: test.h
	> Author: x
	> Mail: x.com
	> Created Time: 2018年10月07日 星期日 11时36分06秒
 ************************************************************************/

#ifndef _TEST_H
#define _TEST_H
#include <stdlib.h>

#define EPS 1e-6
//测试数据统计
struct TestFuncData {
    //统计总数和通过数
    int total, expect;
};

//声明链表中指针类型
typedef void (*test_fucn_t)(struct TestFuncData *);
//声明函数链表
struct FuncData {
    const char *a_str, *b_str;
    test_fucn_t func;               
    struct FuncData *next;         
};

//声明函数类型
void addFuncData(
    const char *a, 
    const char *b,
    test_fucn_t func
);

//
#define TEST(a, b) \
    void a##_haizeix_##b(struct TestFuncData *);\
    __attribute__((constructor))\
    void ADDFUNC_##a##_haizeix_##b(){ \
        addFuncData(#a, #b, a##_haizeix_##b); \
    } \
    void a##_haizeix_##b(struct TestFuncData *__data) 

#define EXPECT(a, b) ({ \
    int temp; \
    printf("%s = %s %s\n", #a, #b, (temp = (a == b)) ? "True" : "False");\
    __data->total += 1;\
    __data->expect += temp;\
})

#define EXPECT_lf(a, b) ({ \
    int temp; \
    printf("%lf = %lf %s\n", a, b, (temp = (fabs(a - b) <= EPS)) ? "True" : "False");\
    __data->total += 1;\
    __data->expect += temp;\
})

int RUN_ALL_TEST();

#endif
