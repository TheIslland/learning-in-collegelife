/*************************************************************************
	> File Name: zuidaprime.c
	> Author: 
	> Mail: 
	> Created Time: 2018年07月25日 星期三 13时11分58秒
 ************************************************************************/

#include<stdio.h>
#define MAX_N 460897024
int main() {
    long long int ans = 0 , m = 460897024;
    for(int i = 2; i * i <= m; i++) {
        if(m % i) continue;
        ans = i;
        if(m % i == 0) {
          m /= i;   
        }
    }
    if(m > ans) ans = m;
    printf("%lld\n",ans);
    return 0;
}
