/*************************************************************************
	> File Name: 466回文数的个数.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Thu Nov  7 02:08:33 2019
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
int is_h(int a) {
    int b = a, c = 0;
    while (a) {
        c = c * 10 + a % 10;
        a /= 10;
    }
    return b == c;
}
int main() {
    int n, ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        is_h(i) && ans++;
    }
    cout << ans << endl;
    return 0;
}
