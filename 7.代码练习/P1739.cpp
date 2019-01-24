/*************************************************************************
	> File Name: P1739.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年01月24日 星期四 11时51分18秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
 
using namespace std;
int main() {
    string str;
    cin >> str;
    int i = 0, flag = 0;
    stack<char> stack1;
    while (str[i] != '@') {
        if (str[i] == '(') {
            stack1.push(str[i]);
        }
        if (str[i] == ')') {
            if (stack1.empty()) {
                flag = 1;
                break;
            }
            stack1.pop();
        }
        i++;
    }
    if (flag) cout << "NO" << endl;
    else if (stack1.empty()) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
