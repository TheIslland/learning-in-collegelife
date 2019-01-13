/*************************************************************************
	> File Name: LeetCode_13_罗马数字转整数.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年01月13日 星期日 18时40分25秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void getVal(char c, int *level, int *val) {
    switch (c) {
        case 'I': *level = 1, *val = 1; break;
        case 'V': *level = 2, *val = 5; break;
        case 'X': *level = 3, *val = 10; break;
        case 'L': *level = 4, *val = 50; break;
        case 'C': *level = 5, *val = 100; break;
        case 'D': *level = 6, *val = 500; break;
        case 'M': *level = 7, *val = 1000; break;
    }
    return ;
}
int romanToInt(char* s) {
    int ans = 0, pre_level = -1, pre_val = 0, level, val;
    for (int i = 0; s[i]; i++) {
        getVal(s[i], &level, &val);
        ans += val;
        if (level > pre_level) {
            ans -= 2 * pre_val;
        }
        pre_val = val, pre_level = level;
    }
    return ans;
}
int main() {
 
    return 0;
}
