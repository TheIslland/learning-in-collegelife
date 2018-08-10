/*************************************************************************
	> File Name: oula7-2.c
	> Author: 
	> Mail: 
	> Created Time: 2018年07月24日 星期二 09时20分05秒
 ************************************************************************/

#include<stdio.h>
#define MAX_N 10000
//这是求最大素因子的算法框架
int prime[MAX_N] = {0};
void init() {
    for(int i = 2; i <= MAX_N; i++) {//for循环中用i而不是i× i目的是便利所有的素数
        if(prime[i]) continue;
        for(int j =  i; j <= MAX_N; j += i) {
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
        printf("%d max prime is %d\n",i,prime[i]);
    }
    printf("%d\n", ans);
    return 0;
}
