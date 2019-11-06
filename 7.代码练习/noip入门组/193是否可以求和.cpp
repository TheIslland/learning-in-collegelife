/*************************************************************************
	> File Name: 193是否可以求和.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Tue Nov  5 14:15:03 2019
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<iomanip>
#include<cstdio>
using namespace std;
#define MAX_N 100005
typedef long long ll;
string binary_search(ll a[], ll l, ll r, ll x) {
    ll mid = (l + r) >> 1;
    while (l <= r) {
        mid = (l + r) >> 1;
        if (a[mid] == x) return "Yes";
        else if (a[mid] > x) r = mid - 1;
        else l = mid + 1;
    }
    return "No";
}
int main() { 
    ll n, k, s;
    ll a[MAX_N] = {0};
    cin >> n;
    for (ll i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    scanf("%lld %lld", &k, &s);
    cout << binary_search(a, 0, n - 1, s - k) << endl;
    return 0;
}
