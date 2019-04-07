/*************************************************************************
	> File Name: 线性筛.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2018年10月08日 星期一 19时02分56秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define MAX 100000

int prime[MAX] = {0};
int min_prime[MAX] = {0};
int sum_factor[MAX] = {0};

void init() {
    for (int i = 2; i < MAX; i++) {
        if (!prime[i]) {
            prime[++prime[0]] = i;
            min_prime[i] = 1;
            sum_factor[i] = 1 + i;
        }
        for (int j = 1; j <= prime[0] && prime[j] * i < MAX; j++) {
            prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) {
                min_prime[i * prime[j]] = min_prime[i] + 1;
                sum_factor[i * prime[j]] = sum_factor[i] / (pow(prime[j], min_prime[i] + 1) - 1) * (pow(prime[j], min_prime[i] + 2) - 1);
                break;
            } else {
                sum_factor[i * prime[j]] = sum_factor[i] + sum_factor[prime[j]];
                min_prime[i * prime[j]] = 1;
            }
        }
    }
}

int main() {
    init();
    int n;
    while (scanf("%d", &n) != EOF) {
        printf("%d\n", sum_factor[n]);
    }
    return 0;
}
