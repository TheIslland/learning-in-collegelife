/*************************************************************************
	> File Name: 198斐波那契数列2.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Tue Nov  5 20:24:19 2019
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<iomanip>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
typedef long long ll;
using namespace std;
ll a[100005] = {0};
ll f(ll n) {
    if (!n) return 0;
    if (n == 1 || n == 2) return 1;
    if (a[n] != 0) return a[n];
    a[n] = (f(n - 1) % 1000000007 + f(n - 2) % 1000000007) % 1000000007;
    return a[n];
}
int main() {
    ll n;
    cin >> n;
    cout << f(n) << endl;
    return 0;
}
