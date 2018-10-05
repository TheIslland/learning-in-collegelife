/*************************************************************************
	> File Name: 任意数组.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2018年10月05日 星期五 17时41分43秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

struct Number {
    int type;
    union {
        int num1;
        float num2;
    } N;
};


void set (Number *n, int num) {
    n->type = 0;
    n->N.num1 = num;
}

void set (Number *n, float num) {
    n->type = 1;
    n->N.num2 = num;
}

void print(Number *n) {
    switch(n->type) {
        case 0: printf("%d\n", n->N.num1); break;
        case 1: printf("%lf\n", n->N.num2); break;
    }
    return ;
}
int main() {
    srand(time(0));
    Number arr[20];
    for (int i = 0; i < 20; i++) {
        int op = rand() % 2;
        switch (op) {
            case 0: {
                int value = rand() % 100;
                set (arr + i, value);
            } break;
            case 1: {
                float value = (1.0 * (rand() % 10000) / 10000) * 100;
                set (arr + i, value);
            } break;
        }
    }
    for (int i = 0; i < 20; i++) {
        print(arr + i);
    }
    return 0;
}
