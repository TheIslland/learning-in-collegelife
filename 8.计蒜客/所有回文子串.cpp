/*************************************************************************
	> File Name: 所有回文子串.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年01月13日 星期日 15时18分37秒
 ************************************************************************/
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int is_valid(char *str, int i, int j) {
    while (i < j) {
        if (str[i++] != str[j--]) return 0;
    }
    return 1;
}

void expand(char *str, int i, int j, int n) {
    while (i >= 0 && j < n && str[i] == str[j]) {
        char c = str[j + 1];
        str[j + 1] = 0;
        printf("%s\n", str + i);
        str[j + 1] = c;
        i--, j++;
    }
    return ;
}

int main() {
    char str[1000];
    scanf("%s", str);
    int len = strlen(str);
    for (int i = 0; i < str[i]; i++) {
        printf("%c\n", str[i]);
        expand(str, i - 1, i + 1, len);
        expand(str, i, i + 1, len);
    }
    return 0;
}
