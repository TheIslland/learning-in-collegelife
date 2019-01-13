/*************************************************************************
	> File Name: LeetCode_165_比较版本号.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年01月13日 星期日 11时08分34秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int compareVersion(char* version1, char* version2) {
    int len1 = strlen(version1), len2 = strlen(version2);
    for (int i = 0, j = 0; i < len1 || j < len2;) {
        int ans1 = 0, ans2 = 0;
        while (i < len1 && version1[i] != '.') {
            ans1 = ans1 * 10 + (version1[i] - 48);
            i++;
        }
        while (j < len2 && version2[j] != '.') {
            ans2 = ans2 * 10 + (version2[j] - 48);
            j++;
        }
        printf("i = %d j = %d\n", i, j);
        printf("%d %d\n", ans1, ans2);
        if (ans1 > ans2) return 1;
        if (ans1 < ans2) return -1;
        i++;
        j++;
    }
    return 0;
}

