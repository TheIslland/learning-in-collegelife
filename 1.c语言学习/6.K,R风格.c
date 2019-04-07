/*************************************************************************
	> File Name: K,R风格.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2018年09月20日 星期四 18时35分34秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int is_prime(x)
int x;
{
    for (int i = 2; i * i < x; i++) {
        if (x % i == 0) return 0;
    }
    return 1;
}
int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        printf("%d\n", is_prime(n));
    }
return 0;
}
