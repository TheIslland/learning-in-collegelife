/*************************************************************************
	> File Name: oula37.c
	> Author: 
	> Mail: 
	> Created Time: 2018年07月27日 星期五 15时12分59秒
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
    int num = x,num1 = x, n = 0, m = 1;
    int judg;
    while(x) {
        n++;
        x /= 10;
        m *= 10;
    }
    m /= 10;
    for(int i = 0; i < n - 1; i++) {
        judg = num / m;
        judg = num - judg * m;
        num = judg;
        m /= 10;
        if(num <= 1)
        return 0;
        if(is_prime[num])
        return 0;
    }
    for(int i = 0; i < n - 1; i++) {
        num1 /= 10;
        if(num1 <= 1)
        return 0;
        if(is_prime[num1])
        return 0;
    }
    return 1;
}
int main() {
    init();
    int ans = 0;
    for(int i = 11; i < 1000000; i++) {
        if(!is_prime[i]) {
            if(reve(i)) {
                ans += i;
                printf("%d\n",i);
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}

