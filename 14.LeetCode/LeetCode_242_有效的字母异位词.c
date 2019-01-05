/*************************************************************************
	> File Name: LeetCode_242_有效的字母异位词.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年01月05日 星期六 21时10分05秒
 ************************************************************************/
bool isAnagram(char* s, char* t) {
    int len1 = strlen(s), len2 = strlen(t);
    int *num = (int *)calloc(sizeof(int), 128);
    for (int i = 0; i < len1; i++) {
        num[s[i]]++;
    }
    for (int i = 0; i < len2; i++) {
        num[t[i]]--;
    }
    for(int i = 0; i < 128; i++) {
        if (num[i]) return false;
    }
    return true;
}
