/************************************************************
    File Name : 312反素数.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2019-11-19 星期二 17:41:58
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
#define MAX_N 20000000
ll prime[MAX_N + 5];
ll ans[MAX_N + 5];

void init() {
    ans[1] = 1;
    for (ll i = 2; i < MAX_N; i++) {
        if (!prime[i]) {
            prime[++prime[0]] = i;
        }
        ans[i] += 2;
        for (ll j = 1; j <= prime[0]; j++) {
            if (i * prime[j] > MAX_N) break;
            prime[i * prime[j]] = 1;
            ans[i * prime[j]] += 1;
            if (i != prime[j]) ans[i * prime[j]] += 1;
            if (i % prime[j] == 0) {
                break;
            }
        }
    }
}

int main() {
    init();
    ll n, max = 0, sum;
    cin >> n;
    for (ll i = 1; i <= n; i++) {
        (ans[i] > max) && (sum = i, max = ans[i]);
    }
    for (int i = 1; i <= 10; i++) {
        cout << i << "is " << ans[i] << endl;
    } cout << sum << endl;
    return 0;
}