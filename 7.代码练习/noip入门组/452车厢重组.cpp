/*************************************************************************
	> File Name: 452车厢重组.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Thu Nov  7 10:35:55 2019
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
#define SWAP(a, b) {\
    __typeof(a) c = a; a = b; b = c;}
int main() {
    int n, ans = 0;
    int a[10005] = {0};
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int flag = 0;
    for (int i = 1; i < n && !flag; i++) {
        flag = 1;
        for (int j = 0; j < n - i; j++) {
            if (a[j] > a[j + 1]) {
                ans++;
                flag = 0;
                SWAP(a[j], a[j + 1]);
            }
        }
    }
    cout << ans << endl;
    return 0;
}
