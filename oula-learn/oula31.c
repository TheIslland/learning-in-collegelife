/*************************************************************************
	> File Name: oula31.c
	> Author: 
	> Mail: 
	> Created Time: 2018年07月27日 星期五 10时27分16秒
 ************************************************************************/

#include<stdio.h>
#define MAX_N 
int w[MAX_N] = {1, 2, 5, 10, 20, 50, 100, 200};
int dp[201] = {0};
int main() {
    dp[0] = 1;
    for(int i = 0; i < 8; i++) {
        for(int j = w[i]; j < 201; j++) {
            dp[j] += dp[j - w[i]];
        }
    }
    printf("%d\n",dp[200]);
    return 0;
}
