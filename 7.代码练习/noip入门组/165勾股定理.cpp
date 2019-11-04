/*************************************************************************
	> File Name: 165勾股定理.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Mon Nov  4 15:05:55 2019
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<iomanip>
#include<cmath>
using namespace std;
typedef long long ll;
int main() {
	ll c, ans = 0;
	cin >> c;
	for (ll i = 1; i < c; i++) {
		ll x = c * c - i * i;
		ll a = (ll)sqrt(x);
		if (i > a) break;
		if (a * a == x) {
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}