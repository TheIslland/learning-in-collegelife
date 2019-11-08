/*************************************************************************
	> File Name: 442走楼梯.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Thu Nov  7 01:12:25 2019
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
ll ans[51] = {0};
void init() {
    ans[1] = 1;
    ans[2] = 2;
    ans[3] = 3;
    for (int i = 4; i < 31; i++) {
        ans[i] = ans[i - 1] + ans[i - 2];
    }
}
int main() {
    ll n;
    cin >> n;
    init();
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << (i < n ? " " : "");
    }
    return 0;
}
