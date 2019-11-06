/*************************************************************************
	> File Name: 208挑选队员.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Wed Nov  6 20:18:00 2019
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
    int n, m, x, ans = 0, flag = 0;
    int a[105] = {0};
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> m;
        a[m]++;
    }
    cin >> x;
    for (int i = 100; i >= 0 && !flag; i--) {
        a[i] >= x && (ans = a[i], flag = 1);
    }    
    cout << ans << endl;
    return 0;
}
