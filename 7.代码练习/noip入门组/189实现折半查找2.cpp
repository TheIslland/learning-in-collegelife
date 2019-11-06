/*************************************************************************
	> File Name: 189实现折半查找2.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Tue Nov  5 10:48:09 2019
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<iomanip>
#include<cstdlib>
#include<cstring>
#include<cstdio>
using namespace std;
typedef long long ll;
int main() {
	ll m[1000005] = { 0 };
	ll n, k;
	scanf("%lld", &n);
	scanf("%lld", &k);
	for (ll i = 0; i < n; i++) {
		ll temp;
		scanf("%lld", &temp);
		m[temp] = i + 1;
	}
	ll x;
	for (ll i = 0; i < k; i++) {
		scanf("%lld", &x);
		cout << (!m[x] ? 0 : m[x]) << (i < k - 1 ? " " : "");
	}
	return 0;
}