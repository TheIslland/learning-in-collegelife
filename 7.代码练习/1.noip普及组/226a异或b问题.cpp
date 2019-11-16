/*************************************************************************
        > File Name: 226a异或b问题.cpp
        > Author: TheIslland
        > Mail: voidland@163.com, 861436930@qq.com
        > Created Time: Sat Nov 16 16:50:11 2019
 ************************************************************************/

#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <string>
typedef long long ll;
using namespace std;

ll poww(ll a, ll b, ll p) {
    int ans = 1, base = a;
    while (b != 0) {
        if (b & 1 != 0) {
            ans = (ans % p * base % p) % p;
        }
        base = base % p * base % p;
        b >>= 1;
    }
    return ans;
}

int main() {
    ll a, b, p, ans;
    cin >> a >> b >> p;
    ans = poww(a, b, p);
    cout << ans % p << endl;
    return 0;
}
