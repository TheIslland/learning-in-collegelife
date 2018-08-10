/*************************************************************************
	> File Name: oula10.c
	> Author: 
	> Mail: 
	> Created Time: 2018年07月24日 星期二 14时08分12秒
 ************************************************************************/

#include<stdio.h>
#include<inttypes.h>
#define MAX_N 2000000
int prime[MAX_N] = {0};
void init() {
    for(int i = 2; i * i <= MAX_N; i++) {
        if(prime[i]) continue;
        for(int j = i * i; j <= MAX_N; j += i) {
            prime[j] = 1;
        }
    }
}
int main() {
    init();
    int64_t ans = 0;
    for(int i = 2; i <= MAX_N; i++) {
        if(!prime[i])
        ans += i;
    }
    printf("%"PRId64 "\n",ans);
    return 0;
}
