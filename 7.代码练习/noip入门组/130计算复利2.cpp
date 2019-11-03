/*************************************************************************
	> File Name: 130计算复利2.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Sun Nov  3 11:31:38 2019
 ************************************************************************/

#include<iostream>
#include<cmath>
#include<algorithm>
#include<iomanip>
using namespace std;
int main() {
    int m, n;
    double ans = 0;
    cin >> m >> n;
    for (int i = 0; i < n; i++) {
        ans = (ans + m) * 1.00417;
    }
    cout << setiosflags(ios::fixed) << setprecision(2) << ans << endl;
    return 0;
}
