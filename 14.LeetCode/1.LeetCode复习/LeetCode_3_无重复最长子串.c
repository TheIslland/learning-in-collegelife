/*************************************************************************
	> File Name: LeetCode_3_无重复最长子串.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2018年11月10日 星期六 10时02分44秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int lengthOfLongestSubstring(char* s) {
    int a[256] = {0};
    int ans = 0;
    for (int i = 0, j = 0; i < strlen(s); i++) {
        a[s[i]] > j ? ans : j - i + 1;
        ans = ans > i - j + 1 ? ans : i - j + 1;
        a[s[i]] = j + 1;
    }
    return ans;
}


int main() {
}
