/*************************************************************************
	> File Name: P1739_表达式括号匹配.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年01月17日 星期四 11时18分41秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int main() {
    stack<char> s1;
    string s;
    cin >> s;
    int i = 0, flag = 0;
    while (s[i] != '@') {
        if (s[i] == '(') s1.push(s[i]);
        if (s[i] == ')') {
            if(s1.empty()) {
                flag = 1;
                break;
            }
            s1.pop();
        }
        i++;
    }
    if (flag) cout << "NO" << endl;
    else if(s1.empty()) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
