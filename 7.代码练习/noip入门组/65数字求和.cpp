/*************************************************************************
	> File Name: 65数字求和.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Thu Nov  7 13:53:52 2019
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
int a[10005] = {0};
void init() {
    for (int i = 1; i * 3 <= 10005; i++) {
        a[3 * i] = 1;
    }
    for (int i = 1; i * 5 <= 10005; i++) {
        a[5 * i] = 1;
    }
    for (int i = 1; i * 7 <= 10005; i++) {
        a[7 * i] = 1;
    }
}
int main() {
    init();
    ll ans = 0;
    for (int i = 1; i < 10001; i++) {
        a[i] &&  (ans += i);
    } 
    cout << ans << endl;
    return 0;
}
