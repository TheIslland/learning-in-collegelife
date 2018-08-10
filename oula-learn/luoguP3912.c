/*************************************************************************
	> File Name: luoguP3912.c
	> Author: 
	> Mail: 
	> Created Time: 2018年07月22日 星期日 18时55分04秒
 ************************************************************************/

#include<stdio.h>
#define MAX_n 10000000
int prime[MAX_n + 5] = {0};
void init() {
    for(int i = 2; i * i <= MAX_n; i++) {
        if(prime[i]) continue;
        for(int j = i * i; j < MAX_n; j += i) {
            prime[j] = 1;
        }
    }
}
int main() {
    init();
    int n;
    int sum = 0; 
    scanf("%d",&n);
    for(int i = 2; i <= n; i++) {
        if(!prime[i])
        sum++;
    }
    printf("%d\n",sum);
    return 0;
}
