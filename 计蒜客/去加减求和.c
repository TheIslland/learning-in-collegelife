/*************************************************************************
	> File Name: 去加减求和.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2018年08月21日 星期二 10时21分02秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main() {
    int a, b;
    scanf("%d %d", &a,&b);
    int c1, d;
    while (b != 0) {
        c1 = a ^ b;
        d = (a & b) << 1;
        a = c1;
        b = d;
    }
    printf("%d\n", a);
return 0;
}
