/*************************************************************************
	> File Name: test.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2018年10月26日 星期五 17时34分46秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void max(int a, int b, int *c) {
    int temp = (a > b ? a : b);
    *c = (*c > temp ? *c : temp);
    return ;
}

int main() {
    int a, b, c = 0;
    while (scanf("%d %d", &a, &b) != EOF) {
        max(a, b, &c);
        printf("%d\n", c);
    } 
    return 0;
}
