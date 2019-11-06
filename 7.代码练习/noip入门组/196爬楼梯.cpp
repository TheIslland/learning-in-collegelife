/*************************************************************************
	> File Name: 196爬楼梯.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Tue Nov  5 19:15:23 2019
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
    ans[1] = 0;
    ans[2] = 1;
    ans[3] = 1;
    for (int i = 4; i < 51; i++) {
        ans[i] = ans[i - 2] + ans[i - 3];
    }
}
int main() {
    ll n;
    cin >> n;
    init();
    cout << ans[n] << endl;
    return 0;
}
