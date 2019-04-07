/*************************************************************************
	> File Name: LeetCode_38_报数.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2018年11月07日 星期三 20时23分32秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* countAndSay(int n) {
    char *a = (char *)malloc(sizeof(char) * 200);
    a[0] = '1';
    if (n <= 1) return a;
    while (n--) {
        int num[100] = {0}, x = 0;
        char last = a[0];
        char *ans = (char *)malloc(sizeof(char) * 200);
        int i;
        for (i = 0; i < strlen(a); i++) {
            if (last == a[i]) {
                num[a[i]]++;  
            } else {
                ans[x++] = num[last] + '0';
                ans[x++] = last;
                num[last] = 0;
                last = a[i];
                num[a[i]]++;
            }
        }
        if (last == a[i -1]) {
                ans[x++] = num[last] + '0';
                ans[x++] = last;
                num[last] = 0;
        }
        a = ans;
        printf("str = %s\n", a);
    }
    return a;
}

int main() {
    printf("%s\n", countAndSay(14)); 
return 0;
}
