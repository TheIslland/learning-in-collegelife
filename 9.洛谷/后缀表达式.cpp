/*************************************************************************
	> File Name: 后缀表达式.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年01月17日 星期四 12时00分39秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
 
using namespace std;

int main() {
    stack<int> s;
    string str;
    cin >> str;
    int ind = 0;
    while (str[ind] != '@') {
        int temp = 0;
        if (str[ind] >= '0' && str[ind] <= '9') {
            while (str[ind] != '.') {
                temp = temp * 10 + (str[ind] - '0');
                ind++;
            }
            s.push(temp);
        } else {
            int b = s.top();
            s.pop();
            int a = s.top();
            s.pop();
            switch(str[ind]) {
                case '+': {
                    s.push(a + b); 
                    break;
                }
                case '-': {
                    s.push(a - b); break;
                }
                case '*': {
                    s.push(a * b); break;
                }
                case '/': {
                    s.push(a / b); break;
                }
            }
        }
        ind++;
    }
    int ans = s.top();
    cout << ans << endl;
    return 0;
}
