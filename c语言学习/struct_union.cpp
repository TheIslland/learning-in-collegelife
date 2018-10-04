/*************************************************************************
	> File Name: struct_union.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2018年10月04日 星期四 10时18分01秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>
//#pragma pack()
//改变存储单元对齐格式
using namespace std;

struct person {
    char name[20];
    int age;
    char gender;
    float height;
};

struct test {
    short a;   //short两个两个读
    char b; //一个一个读
    int c; //只能4个4个读，为保证正确性和完整性从4开始存
    double e; 
};

int main() {
    struct test a;
    printf("sizeof(person) : %d\n", sizeof(struct person)); 
    printf("%p %p %p %p\n", &a.a, &a.b, &a.c, &a.e);
    return 0;
}
