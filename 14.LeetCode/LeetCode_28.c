/*************************************************************************
	> File Name: LeetCode_28.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年01月13日 星期日 18时53分23秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int strStr(char* haystack, char* needle) {     
    int len = 0;
    int pos[256] = {0};
    memset(pos, -1, sizeof(pos));
    for (; needle[len]; len++) pos[needle[len]] = len;
    int i = 0, len2 = strlen(haystack);
    while (i + len <= len2) {
        int j = 0;
        while (needle[j] && needle[j] == haystack[i + j]) ++j;
        if (needle[j] == 0) return i;
        i += (len - pos[haystack[i + len]]);
    }
    return -1;
}
int main() {
 
    return 0;
}
