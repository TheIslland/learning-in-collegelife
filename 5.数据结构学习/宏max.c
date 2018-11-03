/*************************************************************************
	> File Name: 宏max.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2018年11月03日 星期六 19时55分15秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define max(a, b) ({\
    __typeof(a) __a = (a);\
    __typeof(b) __b = (b);\
    ((__a) > (__b) ? (a) : (b));\
})

int main() {
    int x, y, ans;
    ans = max(4 , 5 > 6 ? 5 : 6);
    printf("%d\n", ans);
    return 0;
}
