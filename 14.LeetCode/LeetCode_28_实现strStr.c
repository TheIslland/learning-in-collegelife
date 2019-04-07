/*************************************************************************
	> File Name: LeetCode_28_实现strStr.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年01月05日 星期六 19时27分28秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void get_next(char *pattern, char *next) {
    next[0] = -1;
    for (int i = 1, matten = -1; pattern[i]; i++) {
        while (matten >= 0 && pattern[matten + 1] != pattern[i]) {
            matten = next[matten];
        }
        if (pattern[matten + 1] == pattern[i]) {
            matten++;
        }
        next[i] = matten;
    }
}

int find(char *buffer, char *pattern, char *next) {
    for (int i = 0, matten = -1; i < strlen(buffer); i++) {
        while (matten >= 0 && pattern[matten + 1] != buffer[i]) {
            matten = next[matten];
        }
        if (pattern[matten + 1] == buffer[i]) {
            matten++;
        }
        if (matten = strlen(pattern) - 1) {
            return i - matten;
        }
    }
    return -1;
}

int strStr(char* haystack, char* needle) {           
    char *next = (char *)malloc(sizeof(char) * strlen(needle));
    get_next(needle, next);
    int ans = find(haystack, needle, next);
}
