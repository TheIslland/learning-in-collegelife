/*************************************************************************
	> File Name: 191素数距离.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Tue Nov  5 11:11:49 2019
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<iomanip>
#include<cstdio>
using namespace std;
#define MAX_N 8000005
typedef long long ll;

ll prime[MAX_N] = {0};
void init() {
    for (ll i = 2; i < MAX_N; i++) {
        if (!prime[i]) prime[++prime[0]] = i;
        for (ll j = 1; j <= prime[0] && prime[j] * i  < MAX_N; j++) {
            prime[i * prime[j]] = 1;
            if(i % prime[j] == 0) break;
        }
    }
}
int main() {
    init();
    ll l, r, ans[4] = {0};
    scanf("%lld %lld", &l, &r);
    ll min = 0xffffffff, max = -1;
    int flag = 0;
    for (ll i = 1; i < prime[0]; i++) {
        !flag && (flag = 1);
        if (prime[i] < l)  continue;
        if (prime[i] > r || prime[i + 1] > r) break;
        ll temp = prime[i + 1] - prime[i];
        if (temp > max) {
            ans[2]= prime[i];
            ans[3] = prime[i + 1];
            max = temp;
        }
        if (temp < min) {
            ans[0] = prime[i];
            ans[1] = prime[i + 1];
            min = temp;
        }
    }
    if (!flag) {
        cout << "There are no adjacent primes." << endl;
    } else {
        cout << ans[0] << "," << ans[1] << " are closet, " << ans[2] << "," << ans[3] << " are most distant." << endl;
    }
    
    return 0;
}
