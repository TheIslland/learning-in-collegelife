/*************************************************************************
	> File Name: 440计数问题.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Thu Nov  7 00:51:05 2019
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
int main() {
    int n, x, ans = 0;
    cin >> n >> x;
    for (int i = 1; i <= n; i++) {
        int a = i;
        while (a) {
            a % 10 == x && ans++;
            a /= 10;
        }
    }
    cout << ans << endl;
    return 0;
}
