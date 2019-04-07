/*************************************************************************
	> File Name: P1149.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2018年10月05日 星期五 19时08分42秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int a[10] = {6,2,5,5,4,5,6,3,7,6};

int num[2100] = {6};

void init() {
    for (int i = 0; i < 2100; i++) {
        int temp = i;
        while (temp) {
            num[i] += a[temp % 10];
            temp /= 10;
        }
    }
}

int judg (int x, int y) {
    if(num[x] + num[y - x] == y) return 1;
    return 0;
}

int main() {
    init();
    int n, ans = 0;
    scanf("%d", &n);
    for (int i = 0; i < 1050; i++) {
        for (int j = 0; j < 1050; j++) {
            if(num[i] + num[j] + num[i + j] + 4 == n) ans++;
        }
    }
    printf("%d\n", ans);
    return 0;
}
