/*************************************************************************
	> File Name: KMP.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年01月05日 星期六 12时42分14秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_N 100010

void get_next (char *pattern, char *next) {
    next[0] = -1;
    for (int i = 1, master = -1; pattern[i]; i++) {
        while (master >= 0 && pattern[master + 1] != pattern[i]) {
            master = next[master];
        }
        if (pattern[master + 1] == pattern[i]) {
            master++;
        }
        next[i] = master;
    }
}

int find(char *buffer, char *pattern, char *next) {
    for (int i = 0, master = -1; i < strlen(buffer); i++) {
        while (master >= 0 && pattern[master + 1] != buffer[i]) {
            master = next[master];
        }
        if (pattern[master + 1] == buffer[i]) {
            master++;
        }
        if (master == strlen(pattern) - 1) {
            return i - master;
        }
    }
    return -1;
}

int main() {
    char buffer[MAX_N];
    char pattern[MAX_N];
    char next[MAX_N];
    scanf("%s", buffer);
    scanf("%s", pattern);
    get_next(pattern, next);
    int ans = find(buffer, pattern, next);
    if (ans == -1) {
        printf("No\n");
    } else {
        printf("Yes\n%d\n", ans);
    }
    return 0;
}
