/*************************************************************************
	> File Name: test.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2018年11月06日 星期二 22时16分10秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int the_same(char *str) {
    int a[3000] = {0};
    for (int i = 0; i < strlen(str); i++) {
        if (a[str[i]] == 0) a[str[i]]++;
        else return 0;
    }
    return 1;
}

int lengthOfLongestSubstring(char* s) {
    for (int j = strlen(s); j > 0; j--) {
        int length = j;
    for (int i = 0; i <= strlen(s) - length; i++) {
        char *temp = (char *)malloc(sizeof(char) * length * 2);
        strncpy(temp, s + i, length);
        if (the_same(temp)) return length;
    }
    }
    return 0;
}

int main() {
	int n;
	char str[2000];
    scanf("%s", str);
    n = lengthOfLongestSubstring(str);
    printf("%d\n", n);
    return 0;
}
