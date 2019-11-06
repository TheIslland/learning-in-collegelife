/*************************************************************************
	> File Name: 194两数之和.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Tue Nov  5 14:39:39 2019
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<iomanip>
#include<cstdio>
#include<cstring>
using namespace std;
#define MAX_N 100005
typedef long long ll;
int binary_search(ll a[], ll l, ll r, ll x) {
    ll mid = (l + r) >> 1;
    while (l <= r) {
        mid = (l + r) >> 1;
        if (a[mid] == x) return 1;
        else if (a[mid] > x) r = mid - 1;
        else l = mid + 1;
    }
    return 0;
}
void check(ll a[], ll n, ll s) {
}

int main() { 
    ll n, k, y, s;
    ll a[MAX_N] = {0};
    cin >> n;
    for (ll i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    scanf("%lld", &s);
    for (ll i = 0; i <= s / 2; i++) {
        if (binary_search(a, 0, n - 1, s - a[i])) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}
