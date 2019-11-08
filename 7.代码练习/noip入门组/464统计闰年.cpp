/*************************************************************************
	> File Name: 464统计闰年.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Thu Nov  7 08:41:57 2019
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
    int x, y, ans = 0;
    cin >> x >> y;
    for (int i = x; i <= y; i++) {
        (i % 400 == 0 || (i % 4 == 0 && i % 100)) && ans++;
    }
    cout << ans << endl;
    return 0;
}
