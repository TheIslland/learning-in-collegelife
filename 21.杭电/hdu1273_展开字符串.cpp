/*************************************************************************
	> File Name: hdu1273_展开字符串.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年03月08日 星期五 20时27分32秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>

using namespace std;

string str;

int dfs(int j) {
    int num = 0;
    for (int i = j; i < str.size(); i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            int tem = max(num, 1);
            for (int k = 0; k < tem; k++) {
                cout << str[i];
            }
            num = 0;
        } else if (str[i] >= '0' && str[i] <= '9') {
            num = num * 10 + str[i] - '0';
        } else if (str[i] == '(') {
            int tmp = max(num, 1);
            int m = 0;
            for (int k = 0; k < tmp; ++k) {
                m = dfs(i + 1);
            }
            i = i + m + 1;
            num = 0;
        } else {
            return i - j;
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> str;
        dfs(0);
    }
    return 0;
}
