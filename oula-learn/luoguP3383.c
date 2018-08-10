/*************************************************************************
	> File Name: luoguP3383.c
	> Author: 
	> Mail: 
	> Created Time: 2018年07月22日 星期日 19时23分51秒
 ************************************************************************/

#include<stdio.h>
#define MAX_N 10000000
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
    int n,m,sum = 0;
    int a[100000];
    scanf("%d", &n);
    scanf("%d", &m);
    for(int i = 0; i < m; i++) {
        scanf("%d",&a[i]);
    }
    for(int i = 0;i < m;i++) {
        if(prime[a[i]])
        printf("NO\n");
        else
        printf("YES\n");
    }
    return 0;
}
