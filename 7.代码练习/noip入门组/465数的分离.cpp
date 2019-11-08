/*************************************************************************
	> File Name: 465数的分离.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Thu Nov  7 08:33:02 2019
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
int digit(ll n, int k) {
    int x;
    while (k--) {
        x = n % 10;
        n /= 10;
    }
    return x;
}
int main() {
    ll n, k;
    cin >> n >> k;
    cout << digit(n ,k) << endl;
    return 0;
}
