/*************************************************************************
	> File Name: 456找筷子.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Thu Nov  7 10:01:06 2019
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
    int n, m, ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> m;
        ans ^= m;
    }
    cout << ans << endl;
    return 0;
}
