/*************************************************************************
	> File Name: 快速排序.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2018年10月08日 星期一 17时16分27秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define swap(a, b) {\
    __typeof(a) temp = a;\
    a = b; b = temp;\
}

void quick_sort(int *num, int left, int right) {
    while (left < right) {
        int x = left, y = right, z = num[(x + y) >> 1];
        do {
            while (num[x] < z) x++;
            while (num[y] > z) y--;
            if (x <= y) {
                swap(num[x], num[y]);
                x++; y++;
            }
        } while(x <= y);
        quick_sort(num, x, right);
        right = y;
    }
    return ;
}

int main() {
    int n;
    scanf("%d", &n);
    int a[n + 5];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    quick_sort(a, 0, n);
    for (int i = 0; i < n; i++) {
        printf("%d", a[i]);
        if (i <= n - 1) printf(" ");
    }
    return 0;
}
