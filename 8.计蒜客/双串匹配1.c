/*************************************************************************
	> File Name: 双串匹配1.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年01月15日 星期二 14时00分53秒
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 1000100
void readline(char *str) {
	char ch;
	int ind = 0;
	while (scanf("%c", &ch) != EOF) {
		if (ch == '\n') {
			str[ind] = '\0';
            return ;
		}
		str[ind++] = ch;
	}
	str[ind] = '\0';
	return ;
}
void get_next(char *pattern, char *next) {
    next[0] = -1;
    for (int i = 1, match = -1; pattern[i]; i++) {
        while (match >= 0 && pattern[match + 1] != pattern[i]) match = next[match];
        if (pattern[match + 1] == pattern[i]) {
            match++;
        }
        next[i] = match;
    }
}

int find(char *buffer, char *pattern, char *next) {
    int len = strlen(pattern) - 1;
    for (int i = 0, match = -1; buffer[i]; i++) {
        while (match >= 0 && buffer[i] != pattern[match + 1]) match = next[match];
        if (buffer[i] == pattern[match + 1]) {
            match++;
        }
        if (match == len) {
		return i - match;	
        }
    }
    return -1;
}

int main() {
    char buffer1[MAX_N], buffer2[MAX_N];
    char pattern[1010], next[1010];
	readline(buffer1);
    readline(buffer2);
    readline(pattern);
    int len1 = strlen(buffer1), len2 = strlen(buffer2);
    get_next(pattern, next);
    for (int i = 0; i < len1 && i < len2; i++) {
        buffer1[i] = (buffer1[i] == buffer2[i] ? buffer1[i] : '$');
    }
    printf("%d\n", find(buffer1, pattern, next) + 1);
    return 0;
}
