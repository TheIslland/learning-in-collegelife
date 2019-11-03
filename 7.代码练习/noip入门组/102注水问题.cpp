/*************************************************************************
	> File Name: 102注水问题.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Sat Nov  2 10:18:06 2019
 ************************************************************************/

#include<iostream>
#include<iomanip>
#include<algorithm>
using namespace std;
int main() {
    double a, b, c, t, ans = 0;
    cin >> a >> b >> c >> t;
    ans = t + (1.0 - (1 / a + 1/ b) * t) / (1 / a + 1 / b - 1 / c);
    cout << setiosflags(ios::fixed) << setprecision(2) << ans << endl;
    return 0;
}
