/*************************************************************************
	> File Name: jisuanke.c
	> Author: 
	> Mail: 
	> Created Time: 2018年07月30日 星期一 16时39分39秒
 ************************************************************************/

#include<stdio.h>
int main() {
    int n;
    scanf("%d", &n);
    int temp[10];
    while(n) {
        temp = temp * 10 + n % 2;
    n /= 2;
    }
    printf("%d\n",temp);
}
