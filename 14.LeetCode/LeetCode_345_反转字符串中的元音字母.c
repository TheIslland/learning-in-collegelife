/*************************************************************************
	> File Name: LeetCode_345_反转字符串中的元音字母.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年01月05日 星期六 22时54分11秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* reverseVowels(char* s) {
    int len = strlen(s);
    char *left = s, *right = s + len - 1;
    while (left < right) {
        if (*left != 'a' && *left != 'e' && *left != 'i' && *left != 'o' && *left != 'u' && *left != 'A' && *left != 'E' && *left != 'I' && *left != 'O' && *left != 'U') {
            left++;
            continue ;
        }
        if (*right != 'a' && *right != 'e' && *right != 'i' && *right != 'o' && *right != 'u' && *right != 'A' && *right != 'E' && *right != 'I' && *right != 'O' && *right != 'U'){
            right--;
            continue ;
        }
        printf("%c %c\n", *left, *right);
        char temp = *left;
        *left = *right;
        *right = temp;
        left++;
        right--;
    }
    return s;
}


int main() {
    char str[100];
    char *ans;
    scanf("%s", str);
    ans = reverseVowels(str);
    printf("%s\n", ans);
    return 0;
}
