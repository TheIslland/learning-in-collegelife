/************************************************************
    File Name : 471大整数乘法.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2019-11-20 星期三 20:26:25
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>

using namespace std;
typedef long long ll;

ll ans[1000];

void mul(string str_a, string str_b) {
    int len_a = str_a.length();
    int len_b = str_b.length();
    ll a[1000] = {0}, b[1000] = {0};
    for (int i = 0; i < len_a; i++) {
        a[i] = str_a[len_a - i - 1] - 48;
    }
    for (int i = 0; i < len_b; i++) {
        b[i] = str_b[len_b - i - 1] - 48;
    }
    for (int i = 0; i < len_a; i++) {
        for (int j = 0; j < len_b; j++) {
            ans[i + j] += a[i] * b[j];
        }
        for (int j = 0; j < len_b + i; j++) {
            if (ans[j] < 10) continue;
            ans[j + 1] += ans[j] / 10;
            ans[j] %= 10;
        }
    }
    int len = len_a + len_b + 1;
    while (!ans[len]) len--;
    for (int i = len; i >= 0; i--) {
        cout << ans[i];
    } }

int main() {
    string a, b;
    ll p;
    cin >> a >> b;
    mul(a, b);
    return 0;
}