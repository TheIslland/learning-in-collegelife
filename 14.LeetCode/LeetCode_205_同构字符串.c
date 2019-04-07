/*************************************************************************
	> File Name: LeetCode_205_同构字符串.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年01月05日 星期六 20时42分15秒
 ************************************************************************/
void get_next(char *pattern, char *next) {
    next[0] = -1;
    for (int i = 0, match = -1; pattern[i]; i++) {
        while (match >= 0 && pattern[match + 1] != pattern[i]) {
            match
        }
    }
}

bool isIsomorphic(char* s, char* t) {
    char *next1 = (char *)malloc(sizeof(char) * strlen(s));
    char *next2 = (char *)malloc(sizeof(char) * strlen(t));

}
