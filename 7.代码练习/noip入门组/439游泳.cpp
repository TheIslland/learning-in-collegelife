/*************************************************************************
	> File Name: 439游泳.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Thu Nov  7 00:29:53 2019
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
    double n, x = 2, ans = 0, temp = 0;
    cin >> n;
    while (n > temp) {
        ans++;
        temp += x;
        x *= 0.98
    }
    cout << ans << endl;
    return 0;
}
