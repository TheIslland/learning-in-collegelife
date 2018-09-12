/*************************************************************************
	> File Name: P1177.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2018年09月12日 星期三 18时05分58秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#define max 10000
#define swap(a,b) {\
    __typeof(a) temp = a;\
    a = b; b = temp;\
}
void quick_sort (int *num, int left, int right) {
    while (left < right) {
        int x = left, y = right, z = num[(left + right) >> 1];
        do {
            while (num[x] < z) ++x;
            while (num[y] > z) --y;
            if (x <= y) { //
                swap(num[x], num[y]);
                ++x, --y;
            }
        } while (x <= y);
        quick_sort(num, x, right);
        right = y;
    }
    return ;
} 

int main() {
    int n;
    int num[max + 5] = {0};
    srand((int)time(0));
    n = rand() % 100;
    for (int i = 0; i < n; i++) {
        num[i] = rand() % 1000;
    }
    quick_sort(num, 0, n - 1);
    printf("%d", num[0]);
    for (int i = 1; i < n; i++) {
        printf(" %d", num[i]);
    }
return 0;
}
