/*************************************************************************
	> File Name: oula3.c
	> Author: 
	> Mail: 
	> Created Time: 2018年07月23日 星期一 15时03分26秒
 ************************************************************************/

#include<stdio.h>
#include<inttypes.h>
int main() {
    int64_t ans = 0,m = 600851475143;
    for(int i = 2; i * i <= m; i++) {
        if(m % i) continue;
        //i一定是素数
        ans = i;
        while(m % i == 0) {
            m /= i;
        }
    }
    //A
    //余量m一定是素数
    if(m > ans) ans = m;
    printf("%"PRId64"\n",ans);
    return 0;
}
