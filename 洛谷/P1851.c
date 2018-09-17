/*************************************************************************
	> File Name: P1851.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2018年09月15日 星期六 10时02分26秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define MAX 100000
int prime[MAX] = {0};
int sum_factor[MAX] = {0};
int min_prime[MAX] = {0};
void init() {
    for (int i = 2; i < MAX; i++) {
        if (!prime[i]) {
            prime[++prime[0]] = i;
            sum_factor[i] = 1 + i;
            min_prime[i] = 1;
        }
        for (int j = 1; j <= prime[0] && prime[j] * i < MAX; j++) {
            prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) {
                min_prime[i * prime[j]] = min_prime[i] + 1; 
                sum_factor[i * prime[j]] = sum_factor[i] / (pow(prime[j],min_prime[i] + 1) - 1) * (pow(prime[j],min_prime[i] + 2) - 1);
                break;
            } else {
                sum_factor[i * prime[j]] = sum_factor[i] * sum_factor[prime[j]];
                min_prime[i * prime[j]] = 1;
            }
        }
    }
    for (int i = 2; i < MAX; i++) {
        sum_factor[i] = sum_factor[i] - i;
    }
}
int main() {
    init();
    int s,judg = 0;
    scanf("%d", &s);
    for (int i = s; i < MAX; i++) {
        for (int j = 0; j <MAX; j++) {
            if (sum_factor[i] == j && sum_factor[j] == i && i != j) {
                printf("%d %d\n", i, j);
                judg = 1;
                break;
            }
        }
        if (judg) break;
    }
    while (scanf("%d", &s) != EOF) {
        printf ("%d\n", sum_factor[s]);
    }
    return 0;
}
