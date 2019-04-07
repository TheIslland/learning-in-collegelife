/*************************************************************************
	> File Name: P1449.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年01月24日 星期四 14时34分01秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
 
using namespace std;
int main() {
    stack<int> stack1;
    string s;
    cin >> s;
    int i = 0;
    while (s[i] != '@') {
        if (s[i] >= '0' && s[i] <= '9') {
            int num = 0;
            while (s[i] != '.')  {
                num = num * 10 + (s[i] - '0');
                i++;
            }
            stack1.push(num);
        } else {
            int a = stack1.top();
            stack1.pop();
            int b = stack1.top();
            stack1.pop();
            int temp;
            switch(s[i]) {
                case '+': {
                    temp = b + a;
                }break;
                case '-': {
                    temp = b - a;
                }break;
                case '*': {
                    temp = b * a;
                }break;
                case '/': {
                    temp = b / a;
                }break;
            }
            stack1.push(temp);
        }
        i++;   
    }
    cout << stack1.top() << endl;
    return 0;
}
