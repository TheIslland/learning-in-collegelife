/*************************************************************************
	> File Name: while整数位数.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2018年09月18日 星期二 20时53分22秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        int sum = 0;
        do {
            n = n / 10;
            sum++;
        } while (n);
        //用while 时加一句n = (n == 0);
        printf("%d\n", sum);
    }
    return 0;
}

