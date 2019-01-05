/*************************************************************************
	> File Name: LeetCode_382_赎金信.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年01月05日 星期六 23时40分43秒
 ************************************************************************/
bool canConstruct(char* ransomNote, char* magazine) {
    int a[26] = {0}, b[26] = {0};
    int len1 = strlen(ransomNote), len2 = strlen(magazine);
    if (len1 > len2) return false;
    for (int i = 0; i < len1; i++) {
        a[ransomNote[i] - 'a'] += 1;
    }
    for (int i = 0; i < len2; i++) {
        b[magazine[i] - 'a'] += 1;
    }
    for (int i = 0; i < 26; i++) {
        if (a[i] > b[i]) return false;
    }
    return true;
}
