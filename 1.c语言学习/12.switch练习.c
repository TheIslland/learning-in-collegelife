/*************************************************************************
	> File Name: switch练习.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2018年09月18日 星期二 18时50分11秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        switch (n) {
            case 1: printf("one\n"); break;
            case 2: printf("two\n"); break;
            case 3: printf("three\n"); break;
            default : printf("ERROR\n"); break;
        }
    }
    return 0;
}
