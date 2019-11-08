/*************************************************************************
	> File Name: 444插队问题.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Thu Nov  7 01:26:17 2019
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
    int n, x;
    int a[105];
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> x;
    for (int i = 0; i < n - 1; i++) {
        if (i == x - 1) cout << a[n - 1] << " " << a[i];
        else cout << a[i];
        cout << (i < n - 2 ? " " : "");
    }
    return 0;
}
