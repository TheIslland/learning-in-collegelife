/************************************************************
    File Name : 469进制转一.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2019-11-20 星期三 19:35:52
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
typedef long long ll;
using namespace std;

int main() {
    ll x, sum = 0, temp = 1, len;
    string n;   
    cin >> x >> n;
    for (ll i = n.length() - 1; i >= 0; i--) {
        sum += (n[i] - 48) * temp;
        temp *= x;
    }
    cout << sum << endl;
    return 0;
}