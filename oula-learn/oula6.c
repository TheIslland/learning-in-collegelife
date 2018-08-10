/*************************************************************************
	> File Name: oula6.c
	> Author: 
	> Mail: 
	> Created Time: 2018年mZ**********************************************/

#include<stdio.h>
int main() {
    int i , j, sum1 = 0,sum2 = 0,n = 100;
 //   int sum1 = 5050,sum2 = 2 * 100 * 100 * 100 + 3 *(1 + 100) * 100 - 2*100;
   // printf("%d\n", sum1 * sum1 - sum2);
    for(i = 1; i <= 100; i++) {
        sum1 += i;
        sum2 += i * i;
    }
    printf("%d\n",sum1 * sum1-sum2);
    return 0;
}
