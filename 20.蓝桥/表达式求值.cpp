/*************************************************************************
	> File Name: 表达式求值.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年01月17日 星期四 18时05分05秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
 
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::queue;
using std::stack;
int getNUM(char *str, int *ret) {
    int i = 0, num = 0;
    while (str[i] <= '9' && str[i] >= '0') {
        num = num * 10 % 10000 + (str[i++] - '0');
        num %= 10000;
    }
    *ret = num;
    return i;
}
int getTerm(char *str, int *ret) {
    int i = 0, a;
    if (str[i] == 0) return 0;
    i += getNUM(str + i, ret);
    if (str[i] == 0) return i;
    while (str[i]) {
        if (str[i] == '*') {
            i += getNUM(str + i + 1, &a) + 1;
            *ret = (*ret * a) % 10000;
        }
        else return i;
    }
    return i;
}
int clac(char *str) {
    int i = 0, a, b;
    if (str[i] == 0) return 0;
    i += getTerm(str + i, &a);
    if (str[i] == 0) return a;
    while(str[i]) {
        char op = str[i];
        i += getTerm(str + i + 1, &b) + 1;

        if(op == '+') a = (a + b) % 10000;
    }
    return a;
}
int main() {
    char str[600700];
    cin >> str;
    cout << clac(str) << endl; 
    return 0;
}
