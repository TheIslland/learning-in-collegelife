/*************************************************************************
	> File Name: 解码.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年01月19日 星期六 09时52分13秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

void print(string s) {
    for (int i = 0; s[i]; i++) cout << s[i];
}

int main() {
    string str;
    string temp;
    cin >> str;
    for (int i = 0; str[i];) {
        if (str[i] == '(') {
            i++;
            temp = "";
            while (str[i] != ')') {
                temp += str[i];
                i++;
            }
            i++;
            cout << temp;
        }
        int num = 0, flag = 0;
        while (str[i] >= '0' && str[i] <= '9') {
            num = num * 10 + (str[i] - '0');
            i++;
            flag = 1;
        }
        if (flag) {
            num--;
            while (num--) cout << temp;
        }
        if (str[i] != '(' && str[i] && !(str[i] >= '0' && str[i] <= '9')) {
            temp = str[i];
            cout << temp;
            i++;
        }
    }
    cout << endl;
    return 0;
}
