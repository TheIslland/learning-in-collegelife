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
        //如果遇到重复切换窗口起始点
        i = index[s[j]] > i ? index[s[j]] : i;
        //记录值和当前值比较如果比记录值大记录
        ans = ans > j - i + 1 ? ans : j - i +1;
        index[s[j]] = j + 1;
    }
    return ans;
}

int lengthOfLongestSubstring(char *s) {
    int pos[256] , len = 0;
    memset(pos, -1, sizeof(pos));
    for (int i = 0; s[i]; i++) {
        len += 1;
        if (i - pos[s[i]] < len) len = i - pos[s[i]];
        pos[s[i]] = i;
        if (len > ans) ans = len;
    }
    return ans;
}

//二分查找如果在序列中最终答案，长度为５不出现重复的子串０００００１１１１模型
int check (char *s, int len) {
    if (len == 0) return 1;
    int num[256] = {0}, cnt = 0;
    for (int i = 0; s[i]; i++) {
        num[s[i]] += 1;
        cnt += (num[s[i]] == 1);
        if (i >= len) {
            num[s[i - len]]--;
            cnt -= (num[s[i - len]] == 0);
        }
        if (cnt == len) return 1;
    }
    return 0;
}

int lengthOfLongestSubstring(char *s) {
    int head = 0, tail = strlen(s), mid;
    while (head < tail) {
        mid = (head + tail + 1) >> 1;
        if (check(s, mid) == 1) head = mid;
        else tail = mid - 1;
    }
    return head;
}
