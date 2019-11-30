/************************************************************
    File Name : 22764位整数乘法.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2019-11-20 星期三 19:33:33
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
typedef long long ll;

ll mul(ll a, ll b, ll p) {
    a %= p, b %= p;
    ll ans = 0;
    while (b) {
        if (b & 1) ans += (ans + a) % p;
        a = 2 * a % p, b = b >> 1;
    }
    return ans;
}

int main() {
    ll a, b, p;
    cin >> a >> b >> p;
    cout << mul(a, b, p) << endl;
    return 0;
}