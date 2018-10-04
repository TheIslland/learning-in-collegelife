/*************************************************************************
	> File Name: struct_union.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2018年10月04日 星期四 10时18分01秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <cstdio>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct person {
    char name[20];
    int age;
    char gender;
    float height;
};

struct test {
    char b;
    short a;
    int c;
    double e;
};

struct Number {
    int type; // 0->int or 1->double
    union {
        int num1;
        float num2;
    } N;
};

void print(Number *n) {
    switch (n->type) {
        case 0: printf("%d\n", n->N.num1); break;
        case 1: printf("%f\n", n->N.num2); break;
    }
    return ;
}

void set(Number *n, float num) {
    n->type = 1;
    n->N.num2 = num;
}

void set(Number *n, int num) {
    n->type = 0;
    n->N.num1 = num;
}

int main() {
    srand(time(0));
    struct test a;
    printf("sizeof(person) : %d\n", sizeof(struct person));
    printf("%p %p %p", &a.a, &a.b, &a.c);
    #define MAX_N 20
    Number arr[MAX_N];
    for (int i = 0; i < MAX_N; i++) {
        int op = rand() % 2;
        switch (op) {
            case 0: {
                int value = rand() % 100;
                set(arr + i, value);
            } break;
            case 1: {
                float value = (1.0 * (rand() % 10000) / 10000) * 100;
                set(arr + i, value);
            } break;
        }
    }
    for (int i = 0; i < MAX_N; i++) {
        print(arr + i);
    }
    arr[0].N.num2 = 1.0;
    printf("arr[0].N.num1 = %d\n", arr[0].N.num1);
    printf("arr[0].N.num1 = %x\n", arr[0].N.num1);
    return 0;
}
