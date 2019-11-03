/*************************************************************************
	> File Name: 134十一的倍数.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Sun Nov  3 14:23:29 2019
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
int main() {
    int a, b;
    int x[1005] = {0};
    cin >> a >> b;
    for (int i = 11; i <= b; i += 11) {
        x[++x[0]] = i;
    }
    for (int i = 1; i <= x[0]; i++) {
        cout << x[i] << (i < x[0] ? " " : "");
    }
    return 0;
}
