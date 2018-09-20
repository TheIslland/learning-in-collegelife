/*************************************************************************
	> File Name: 阶乘函数.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2018年09月20日 星期四 18时43分35秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define max 1000
typedef long long int llint;
int jiecheng[max] = {1};
llint level_num (int x) {
    if (jiecheng[x]) return jiecheng[x];
    return jiecheng[x] = x * level_num(x - 1);
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%lld\n", level_num(n));
return 0;
}
