/*************************************************************************
	> File Name: oula4.c
	> Author: 
	> Mail: 
	> Created Time: 2018年07月23日 星期一 15时42分15秒
 ************************************************************************/

#include<stdio.h>
int reversal(int x) {
    int cmp = x , sum = 0;
    while(x) {
        sum = sum * 10 + x % 10;
        x /= 10;
    }
    return sum == cmp;
}
int main() {
    int ans = 0;
    for(int i = 100; i < 1000; i++) {
        for(int j = 100; j < 1000; j++) {
            if(reversal(i * j) && i * j >= ans) {
                ans = i * j;
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
