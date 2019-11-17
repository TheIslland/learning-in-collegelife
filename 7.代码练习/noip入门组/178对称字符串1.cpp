/************************************************************
    File Name : 178对称字符串1.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2019-11-16 星期六 20:07:31
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

int main() {
    string a, b, c;
    int n;
    c = "A";
    cin >> n;
    for (int i = 0; i < n; i++) {
        a = b;
        a += c;
        a += b;
        b = a;
        c[0]++;
    }
    cout << a << endl;
    return 0;
}