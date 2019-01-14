/*************************************************************************
	> File Name: 集合减法.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年01月14日 星期一 12时16分21秒
 ************************************************************************/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

void FUNC(int *num, int n) {
    for (int i = 1; i < n; i++) {
        for (int j = i; j > 0; j--) {
            if (num[j] < num[j - 1]) swap(num[j], num[j - 1]);
        }
    }
    return ;
}

int main() {
    int n, m;
    while (scanf("%d %d", &n, &m) != EOF) {
        if (n == 0 && m == 0) break;
        int a[105] = {0}, b[105] = {0};
        for (int i = 0; i < n; i++) scanf("%d", &a[i]);
        for (int i = 0; i < m; i++) scanf("%d", &b[i]);
        FUNC(a, n);
        FUNC(b, m);
        int j = 0, judg = 0;
        for (int i = 0; i < n;) {
            if (j >= m) {
                printf("%d ", a[i]);
                judg = 1;
                ++i;
                continue;
            }
            if (a[i] == b[j]) {
                ++i, ++j;
            } else if (a[i] > b[j]) {
                ++j;
            } else {
                printf("%d ", a[i]);
                judg = 1;
                ++i;
            }
        }
        if (!judg) printf("NULL");
        printf("\n");
    }
    return 0;
}
