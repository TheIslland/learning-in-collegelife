/*************************************************************************
	> File Name: 100计算复利.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Sat Nov  2 10:03:03 2019
 ************************************************************************/

#include<iostream>
#include<iomanip>
#include<algorithm>
using namespace std;
int main() {
    double n, ans = 0;
    cin >> n;
    for (int i = 0; i < 6; i++) {
        ans = (ans + n) * 1.00417;
    }
    cout << setiosflags(ios::fixed) << setprecision(2) << ans << endl;
    return 0;
}
