/*************************************************************************
	> File Name: 190路飞的猜想.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Tue Nov  5 10:52:59 2019
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
typedef long long ll;
#define MAX_N 8000005
ll prime[MAX_N] = {0};
void init() {
    for (ll i = 2; i < MAX_N; i++) {
        if (prime[i]) continue;
        for (ll j = 2 * i; j < MAX_N; j += i) {
            prime[j] = 1;
        }
    }
}
int main() {
    prime[0] = prime[1] = 1;
    init();
    ll n, ans = 0;
    cin >> n;
    for (ll i = 2; i <= n / 2; i++) {
        if (!prime[i] && !prime[n - i]) ans++;
    }
    cout << ans << endl;
    return 0;
}
