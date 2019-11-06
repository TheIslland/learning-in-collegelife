/*************************************************************************
	> File Name: 183递归函数.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Tue Nov  5 01:04:16 2019
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
int f(int x) {
    if (x <= 0) return 0;
    if (x == 1) return 1;
    if (x > 1 && x % 2 == 0) return 3 * f(x / 2) - 1;
    if (x > 1 && x % 2 == 1) return 3 * f((x + 1) / 2) - 1;
}
int main() {
    int n;
    cin >> n;
    cout << f(n) << endl;
    return 0;
}
