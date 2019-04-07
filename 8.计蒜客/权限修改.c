/*************************************************************************
	> File Name: h.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年10月05日 星期五 12时20分37秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>

int main() {
    char a[10];
    int ans = 0, temp = 1;
    while (scanf("%s", a) != EOF) {
        if (a[0] == '-') {
            for (int i = 0; i < strlen(a); i++) {
                if (a[i] == 'r') ans = (ans | 4) ^ 4;
                if (a[i] == 'w') ans = (ans | 2) ^ 2;
                if (a[i] == 'x') ans = (ans | 1) ^ 1;
            }
        } else {
            for (int i = 0; i < strlen(a); i++) {
                if (a[i] == 'r') ans = ans | 4;
                if (a[i] == 'w') ans = ans | 2;
                if (a[i] == 'x') ans = ans | 1;
            }
        }
        memset(a, 0, sizeof(a));
    }
    printf("%d\n", ans);
    return 0;
}
