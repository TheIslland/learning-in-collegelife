/*************************************************************************
	> File Name: LeetCode_3_没有重复的最长子串.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2018年11月07日 星期三 17时22分14秒
 ************************************************************************/

int lengthOfLongestSubstring(char* s) {
    int n = strlen(s), ans = 0;
    int index[256] = {0};
    for (int j = 0, i = 0; j < n; j++) {
        i = index[s[j]] > i ? index[s[j]] : i;
        ans = ans > j - i + 1 ? ans : j - i +1;
        index[s[j]] = j + 1;
    }
    return ans;
}
 
