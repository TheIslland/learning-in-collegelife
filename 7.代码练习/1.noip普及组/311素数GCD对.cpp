/************************************************************
    File Name : 311素数GCD对.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2019-11-17 星期天 17:49:21
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
#define MAX_N 1000000
ll prime[MAX_N + 5], phi[MAX_N + 5];

void init() {
    for (ll i = 2; i <= MAX_N; i++) {
        if (!prime[i]) {
            prime[++prime[0]] = i;
            phi[i] = i - 1;
        }
        for (ll j = 1; j <= prime[0]; j++) {
            if (i * prime[j] > MAX_N) break;
            prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) {
                phi[i * prime[j]] = phi[i] * prime[j];
                break;
            } else {
                phi[i * prime[j]] = phi[i] * (prime[j] - 1);
            }
        }
    }
    return;
}
int main() { 
    init();
    ll n, k = prime[0], ans = 0;
    cin >> n;
    while (k && prime[k] > n) k--;
    ans += k;
    for (ll i = 2; i <= n; i++) {
        while (k && prime[k] * i > n) k--;
        ans += 2 * phi[i] * k;
    }
    cout << ans << endl;
    return 0;
}