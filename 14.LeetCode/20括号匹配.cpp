/************************************************************
    File Name : 20括号匹配.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2019-11-16 星期六 18:39:05
************************************************************/
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>

using namespace std;
class Solution {
public:
    bool isValid(string s) {
        int len = s.length();
        //if (s.length() % 2) return flase;
        stack<char> p;
        for (int i = 0; i < len; i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                p.push(s[i]);
            } else {
                if (p.empty()) return false;
                int temp = s[i] - p.top();
                if ( temp != 1 && temp != 2) return false;
                p.pop();
            }
        }
        return p.empty();
    }
};
int main() {
    
    return 0;
}