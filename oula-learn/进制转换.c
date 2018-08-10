/*************************************************************************
	> File Name: 进制转换.c
	> Author: 
	> Mail: 
	> Created Time: 2018年08月07日 星期二 16时27分48秒
 ************************************************************************/

#include<stdio.h>
int zhuanhuan(int x) {
    int ans = x, sum = 0, k = 1;
    while(x) {
        sum += x % 2 * k;
        k *= 10;
        x /= 2;
    }
    printf("%d\n",sum);
}
int main() {
    zhuanhuan(37);
    return 0;
}
