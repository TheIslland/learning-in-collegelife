/*************************************************************************
	> File Name: 457欢乐的跳.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Thu Nov  7 09:41:53 2019
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<iomanip>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cmath>
typedef long long ll;
using namespace std;
int main() {
    int n;
    ll a[1005];
    int b[1005] = {0};
    cin >> n;
    for (int i = 0 ; i < n; i++) {
        cin >> a[i];
        if (i > 0) {
            ll temp = abs(a[i] - a[i - 1]) ;
            if (temp <= n) b[temp] = 1;
        }
    }
    int flag = 0;
    for (int i = 1; (i <= n - 1) && !flag; i++) {
        !a[i] && (flag = 1);
    }
    cout << (flag ? "Not jolly" : "Jolly") << endl;
    return 0;
}
