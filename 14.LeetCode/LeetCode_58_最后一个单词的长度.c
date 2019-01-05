/*************************************************************************
	> File Name: LeetCode_58_最后一个单词的长度.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年01月05日 星期六 20时33分33秒
 ************************************************************************/
int lengthOfLastWord(char* s) {
    int ans = 0, cnt = 0;
    for (int i = strlen(s) - 1; i >= 0; --i) {
        if (s[i] == ' ' && ans == 0) {
            continue ;
        } 
        if (s[i] == ' ' && ans > 0) {
            break;
        }
        ans++;
    }
    return ans;
}
