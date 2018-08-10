/*************************************************************************
	> File Name: oula20.c
	> Author: 
	> Mail: 
	> Created Time: 2018年07月29日 星期日 15时52分54秒
 ************************************************************************/

#include<stdio.h>
#define MAX_N 30
int is_factorial[MAX_N + 5] = {1,1};
void jiecheng() {
    for(int i = 1; i <= 100; i++) {
        for(int j = 1; j <= is_factorial[0]; j++) {
            is_factorial[j] *= i;
        }
	        for(int k = 1; k <= is_factorial[0]; ++k) {
                if(is_factorial[k] >=10) {
                    is_factorial[k + 1] += is_factorial[k] / 10;
                    is_factorial[k] %= 10;
                    if(k == is_factorial[0]) is_factorial[0] += 1;
                }
            } 
        }
    }

int main() {
    int ans = 0;
    jiecheng();
    for(int i = 1; i <= is_factorial[0]; i++) {
        ans += is_factorial[i];
    }
    printf("%d\n", ans);
    return 0;
}
