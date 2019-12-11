/************************************************************
    File Name : 82伐木.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2019-12-11 星期三 20:37:26
************************************************************/
#include <algorithm>
#include <cinttypes>
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
#define MAX_N 1000000

ll a[MAX_N + 5], sum, n, m;

void binary_search(ll l, ll r) {
    ll mid;
    while (l <= r) {
        mid = (l + r) >> 1;
        sum = 0;
        for (ll i = 0; i < n; i++) {
            if (mid < a[i]) sum += a[i] - mid;
        }
        if (sum < m) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << l - 1 << endl;
    return;
}

int main() {
    ll max = -1;
    cin >> n >> m;
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
        a[i] > max && (max = a[i]);
    }
    binary_search(0, max);
    return 0;
}