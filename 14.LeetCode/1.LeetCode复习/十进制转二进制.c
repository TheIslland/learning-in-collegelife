/*************************************************************************
	> File Name: test.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2018年11月10日 星期六 09时39分45秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int zhuan(int x) {
    int ans = 0, k = 1;
    while (x) {
        ans += x % 2 * k;
        k *= 10;
        x = x / 2;
    }
    return ans;
}
int main() {
    printf("%d\n", zhuan(2));
    printf("%d\n", zhuan(4));
    printf("%d\n", zhuan(8));
    printf("%d\n", zhuan(16));
    printf("%d\n", zhuan(32));
    return 0;
}
