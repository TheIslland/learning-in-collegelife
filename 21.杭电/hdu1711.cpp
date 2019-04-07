/*************************************************************************
	> File Name: hdu1711.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年01月25日 星期五 09时31分30秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

void get_next(int *pattern, int *next, int len) {
    next[0] = -1;
    for (int i = 1, match = -1; i < len; i++) {
        while (match >= 0 && pattern[match + 1] != pattern[i]) match = next[match];
        if (pattern[match + 1] == pattern[i]) match++;
        next[i] = match;
    }
    return ;
}

int KMP(int *buff, int *pattern, int *next, int n, int m) {
    for (int i = 0, match = -1; i < n; i++) {
        while (match >= 0 && pattern[match + 1] != buff[i]) match = next[match];
        if (pattern[match + 1] == buff[i]) match++;
        if (match == m - 1) return i - match + 1;
    }
    return -1;
}

#define MAX_N 1000050
int num1[MAX_N], num2[MAX_N];

int main() {
    int n, m, x;
    cin >> x;
    while (x--) {
        cin >> n >> m;
        int next[m];
        for (int i = 0; i < n; i++) {
            cin >> num1[i];
        }
        for (int i = 0; i < m; i++) {
            cin >> num2[i];
        }
        get_next(num2, next, m);
        cout << KMP(num1, num2, next, n, m) << endl;
    }
    return 0;
}
