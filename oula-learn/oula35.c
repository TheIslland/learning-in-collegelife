/*************************************************************************
	> File Name: oula35.c
	> Author: 
	> Mail: 
	> Created Time: 2018年07月27日 星期五 15时11分59秒
 ************************************************************************/

#include<stdio.h>
#include<math.h>
#define MAX_N 1000000
int is_prime[MAX_N] = {0};
void init() {
    for(int i = 2; i * i < MAX_N; i++) {
        if(is_prime[i]) continue;
        for(int j = i * i; j < MAX_N; j += i) {
            is_prime[j] = 1;
        }
    }
}
int reve(int x) {
    int num = x, n = 0, m = 1;
    int judg;
    while(x) {
        n++;
        x /= 10;
        m *= 10;
    }
    while(n--) {
        judg = num % 10;
        judg = judg * (m / 10) + num / 10;
        num = judg;
        if(is_prime[num])
        return 0;
    }
    return 1;
}
int main() {
    init();
    int ans = 0;
    for(int i = 2; i < 1000000; i++) {
        if(!is_prime[i]) {
            if(reve(i)) {
                ans++;
                printf("%d\n",i);
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
