/*************************************************************************
	> File Name: 189实现折半查找.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Tue Nov  5 09:55:41 2019
 ************************************************************************/


#include<iostream>
#include<algorithm>
#include<iomanip>
#include<cstdlib>
#include<cstring>
#include<cstdio>
using namespace std;
typedef long long ll;
ll mem[1000005];
ll binary_search(ll *m, ll l, ll r, ll x) {
	if (mem[x] != -1) return mem[x];
	ll mid;
	while (l <= r) {
		mid = (l + r) >> 1;
		if (m[mid] == x) {
			mem[x] = mid + 1;
			return mem[x];
		}
		else if (m[mid] > x) r = mid - 1;
		else l = mid + 1;
	}
	return 0;
}
int main() {
	memset(mem, -1, sizeof(ll) * 1000005);
	ll m[1000005] = { 0 };
	ll n, k;
	scanf("%lld", &n);
	scanf("%lld", &k);
	for (ll i = 0; i < n; i++) {
		scanf("%lld", &m[i]);
	}
	ll x;
	for (ll i = 0; i < k; i++) {
		scanf("%lld", &x);
		cout << binary_search(m, 0, n - 1, x) << (i < k - 1 ? " " : "");
	}
	return 0;
}