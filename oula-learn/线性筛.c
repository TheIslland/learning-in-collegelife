/*************************************************************************
	> File Name: 线性筛.c
	> Author: 
	> Mail: 
	> Created Time: 2018年07月26日 星期四 14时33分40秒
 ************************************************************************/

#include<stdio.h>
#define MAX_N 10000
int is_prime[MAX_N + 5] = {0};
int prime[MAX_N + 5] = {0};
int main() {
    for(int i = 2; i <= MAX_N; i++) {
        if(!is_prime[i]) {
            prime[++prime[0]] = i;
        }
        for(int j = 1,p = prime[1]; j <= prime[0]; j += 1,p = prime[j]) {
            if(p * i > MAX_N) break;
            is_prime[p * i] = 1;
            if(i % p == 0) break;
        }
    }
    for(int i = 1; i <= prime[0]; i++) {        
        printf("%d ",prime[i]);
    }
    return 0;
}
/*#define MAX_N 10000
 * int prime[MAX_N + 5] = {0};
 * int main(){
 * for(int i = 2; i <= MAX_N; i++) {
 *if(!prime[i]) prime[++prime[0]];
    for(int j = 1; j < prime[0]&&prime[j] * i <= MAX_N; ++j) {
    prime[prime[j] * i] = 1;
    if(i * prime[j] == 0) break;
    }
 * }
 * }
 */
