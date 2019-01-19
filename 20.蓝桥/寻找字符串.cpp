/*************************************************************************
	> File Name: 寻找字符串.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年01月18日 星期五 20时02分23秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;
void get_next(string pattern, char *next) {
    next[0] = -1;
    for (int i = 1, match = -1; pattern[i]; i++) {
        while (match >= 0 && pattern[match + 1] != pattern[i]) {
            match = next[match];
        } 
        if (pattern[match + 1] == pattern[i]) {
            match++;
        }
        next[i] = match;
    }
}

int find(string buffer, string pattern, char *next) {
    int cnt = 0, len =  pattern.length() - 1;
    for (int i = 0, match = -1; buffer[i]; i++) {
        while (match >= 0 && buffer[i] != pattern[match + 1]) {
            match = next[match];
        }
        if (buffer[i] == pattern[match + 1]) match++;
        if (len == match) cnt++;
    }
    return cnt;
}

int main() {
    string buffer, pattern;
    getline(cin, buffer);
    cin >> pattern;
    char next[pattern.length()];
    get_next(pattern, next);
    int ans = find(buffer, pattern, next);
    cout << ans << endl;
    return 0;
}
