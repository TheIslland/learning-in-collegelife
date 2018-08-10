/*************************************************************************
	> File Name: oula7-1.c
	> Author: 
	> Mail: 
	> Created Time: 2018年07月24日 星期二 10时00分12秒
 ************************************************************************/

#include<stdio.h>
#define MAX_N 10000
//这是求最小素因子的算法框架
int prime[MAX_N] = {0};
void init() {
    for(int i = 2; i * i <= MAX_N; i++) {
        if(prime[i]) continue;
        for(int j = i * i; j <= MAX_N; j += i) {
		if(prime[i]) continue;            
		prime[j] = i;
        }
    }
    for(int i = 2; i <= MAX_N; i++) {
        if(prime[i]) continue;
        prime[i] = i;
    }
}
int main() {
    init();
    int ans = 0;
    for(int i = 2; i <= MAX_N; i++) {
        printf("%d min prime is %d\n",i,prime[i]);
    }
    printf("%d\n", ans);
    return 0;
}
