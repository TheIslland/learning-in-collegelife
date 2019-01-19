/*************************************************************************
	> File Name: 子串匹配.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年01月16日 星期三 19时50分42秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

void get_next(string pattern, int *next) {
    next[0] = -1;
    for (int i = 1, match = -1; pattern[i]; i++) {
        while (match >= 0 && pattern[match + 1] != pattern[i]) match = next[match];
        if (pattern[match + 1] == pattern[i]) match++;
        next[i] = match;
    }
}

int find(string buffer, string pattern, int *next) {
    int cnt = 0, len = pattern.length() - 1;
    for (int i = 0, match = -1; buffer[i]; i++) {
        while (match >= 0 && pattern[match + 1] != buffer[i]) match = next[match];
        if (buffer[i] == pattern[match + 1]) match++;
        if  (match == len) {
            cnt++;
        }
    }
    return cnt;
}
int main() {
    string str, pattern, buffer = "", temp;
    cin >> str >> pattern;
    for (int i = 0 ; i < str.length();) {
        if (str[i] == '[') {
            i++;
            temp = "";
            while (str[i] != ']') {
                temp += str[i];
                i++;
            }
            i++;
        }
        int num = 0;
        while (str[i] >= '0' && str[i] <= '9') {
            num  = num * 10 + (str[i] - '0');
            i++;
        }
        while (num--) {
            buffer += temp;
        }
        while (str[i] && str[i] != '[' && !(str[i] >= '0' && str[i] <= '9')) {
            buffer += str[i];
            i++;
        }
    }
    int next[pattern.length()];
    get_next(pattern, next);
    cout << find(buffer, pattern, next) << endl;
    return 0;
}
