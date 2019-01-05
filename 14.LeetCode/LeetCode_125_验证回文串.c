/*************************************************************************
	> File Name: LeetCode_125_验证回文串.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年01月05日 星期六 20时39分10秒
 ************************************************************************/
bool isPalindrome(char* s) {
    int len = strlen(s);
    if (!len) return true;
    char *p = s, *q = s + len - 1;
    while (p < q) {
        if (*p < 48 || (*p > 57 && *p < 65) || (*p > 90 && *p < 97) || *p > 122) {p++; continue;}
        if (*q < 48 || (*q > 57 && *q < 65) || (*q > 90 && *q < 97) || *q > 122) {q--; continue;}
        if (tolower(*p++) != tolower(*q--)) return false;
    }
    return true;
}
