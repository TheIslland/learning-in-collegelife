/*************************************************************************
	> File Name: kmp.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年01月06日 星期日 10时37分45秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void get_next(char *pattern, char *next) {
    next[0] = -1;
    for (int i = 1, match = -1; pattern[i]; i++) {
        while (match >= 0 && pattern[match + 1] != pattern[i]) {
            match = next[match];
        }
        if (pattern[match + 1] == pattern[i]) {
            match++;
        }
        next[i] = match;
    }
}

int find(char *buffer, char *pattern, char *next) {
    for (int i = 0, match = -1; i < strlen(buffer); i++) {
        while (match >= 0 && pattern[match + 1] != buffer[i]) {
            match = next[match];
        }
        if (pattern[match + 1] == buffer[i]) {
            match++;
        }
        if (match == strlen(pattern) - 1) {
            return i - match;
        }
    } 
    return -1;
}

int main() {
    char buffer[20];
    char pattern[20];
    char next[20];
    scanf("%s", buffer);
    scanf("%s", pattern);
    get_next(pattern, next);
    int ans = find(buffer, pattern, next);
    printf("%d\n", ans);
    return 0;
}
