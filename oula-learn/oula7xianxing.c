/*************************************************************************
	> File Name: oula7xianxing.c
	> Author: 
	> Mail: 
	> Created Time: 2018年07月24日 星期二 10时17分17秒
 ************************************************************************/

#include<stdio.h>
#define MAX_N 10000
int is_prime[MAX_N + 5] = {0};
int prime[MAX_N + 5] = {0};
int main() {
    for(int M = 2; M <= MAX_N; M++) {
        if(!is_prime[M]) {
            prime[++prime[0]] = M;
        }
      for(int i = 1, p = prime[1]; i <= prime[0]; i += 1, p = prime[i]) {
        if(p * M > MAX_N) break;
          is_prime[p * M] = 1;
        if(M % p == 0) break;  
        }
    }
    for(int i = 1; i <= prime[0]; i++) {
        printf("%d ",prime[i]);
    }
    printf("\n");
    int n;
    while(scanf("%d", &n) != EOF) {
        printf("%d is prime = %d\n",n, is_prime[n]);
    }
    return 0;
}
