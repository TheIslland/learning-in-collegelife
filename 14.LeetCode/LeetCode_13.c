/*************************************************************************
	> File Name: LeetCode_13.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年01月05日 星期六 18时13分51秒
 ************************************************************************/
int romanToInt(char* s) {
    int arr[128] = {0};
    arr[73] = 1;
    arr[86] = 5;
    arr[88] = 10;
    arr[76] = 50;
    arr[67] = 100;
    arr[68] = 500;
    arr[77] = 1000;
    int ans = 0;
    for (int i = 0; i < strlen(s); i++) {
        if (i + 1 <= strlen(s) - 1 && (s[i] == 'I' && (s[i + 1] == 'V' || s[i + 1] == 'X'))) {
            ans -= 1;
            continue;
        }      
        if (i + 1 <= strlen(s) - 1 && (s[i] == 'X' && (s[i + 1] == 'L' || s[i + 1] == 'C'))) {
            ans -= 10;
            continue;
        }      
        if (i + 1 <= strlen(s) - 1 && (s[i] == 'C' && (s[i + 1] == 'D' || s[i + 1] == 'M'))) {
            ans -= 100;
            continue;
        }      
        ans += arr[s[i]];
    }
    return ans;
}
