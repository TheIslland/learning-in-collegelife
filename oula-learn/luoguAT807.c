/*************************************************************************
	> File Name: luoguAT807.c
	> Author: 
	> Mail: 
	> Created Time: 2018年07月22日 星期日 17时06分07秒
 ************************************************************************/

#include<stdio.h>
#define MAX_N 1000000
int prime[MAX_N + 5] = {0};
void init() {
    for(int i = 2; i * i <= MAX_N; i++) {
        if(prime[i]) {
            continue;
        }
        for(int j = i* i; j <= MAX_N; j += i) {
            prime[j] = 1;               
        }
    }

    return;
}
int main() {
    int n;
    scanf("%d",&n);
    init();
    if(prime[n])
    printf("NO\n");
    else
    printf("YES\n");
    return 0;
}
