/*************************************************************************
	> File Name: 2007.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2018年11月11日 星期日 10时19分26秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define swap(a, b) {\
    __typeof(a) __temp = (a); (a) = (b); (b) = __temp;\
}

int main() {
    int x, y;
    while (scanf("%d %d", &x, &y) != EOF) {
        int sum2 = 0, sum3 = 0;
        if (x > y) swap(x, y);
        for (int i = x; i <= y; i++) {
            if (i % 2) {
                sum3 += i * i * i;
            } else {
                sum2 += i * i;
            }
        }
        printf("%d %d\n", sum2, sum3);
    }
    return 0;
}
