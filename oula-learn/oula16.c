/*************************************************************************
	> File Name: oula16.c
	> Author: 
	> Mail: 
	> Created Time: 2018年07月26日 星期四 18时14分02秒
 ************************************************************************/

#include<stdio.h>
int main() {
    int ans[3500];
    ans[0] = 4;
    ans[1] = 4;
    ans[2] = 2;
    ans[3] = 0;
    ans[4] = 1;
    for(int i = 1 ; i <= 99; ++i) {
        for(int j = 1; j <= ans[0]; ++j) {
            ans[j] *= 1024;//还可以写成1024 × 1024的50次方进行加速
         }     
        for(int k = 1; k <= ans[0]; ++k) {
            if(ans[k] >= 10) {
                ans[k + 1] += ans[k] / 10;
                ans[k] %= 10;
                if(k == ans[0])
                ans[0] += 1;
                //ans[0] += (k == ans[0]);操作QWQ
            }
        }
    }
     int sum = 0;
    for(int i = 1; i <= ans[0]; i++) {
        sum += ans[i];
    }
    printf("%d\n",sum);
    return 0;
}
