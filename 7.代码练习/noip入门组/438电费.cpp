/*************************************************************************
	> File Name: 438电费.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Thu Nov  7 00:15:59 2019
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
    double n, m, ans;
    cin >> n;
    if (n < 241) {
        ans = n * 0.4783;
    } else if (n <= 400) {
        ans = 240 * 0.4783 + (n - 240) * 0.5283;
    } else {
        ans = 240 * 0.4783 + 160 * 0.5283 + (n - 400) * 0.7783;
    }
    cout << setiosflags(ios::fixed) << setprecision(1) << ans << endl;
    return 0;
}
