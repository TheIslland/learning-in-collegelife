/*************************************************************************
	> File Name: 99求出跑道长度.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Fri Nov  1 20:50:38 2019
 ************************************************************************/

#include<iostream>
#include<iomanip>
#include<algorithm>
using namespace std;
int main() {
    double a, v;
    cin >> v >> a;
    double ans = (v * v * 1.0) / (2.0 * a);
    cout << setiosflags(ios::fixed) << setprecision(2) << ans << endl;
    return 0;
}
