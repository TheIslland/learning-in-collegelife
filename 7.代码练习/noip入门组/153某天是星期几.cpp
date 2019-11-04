/*************************************************************************
	> File Name: 153某天是星期几.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Sun Nov  3 23:09:32 2019
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
int main() {
    int h, y, m, d, j, k;
    cin >> y >> m >> d;
    if (m == 1 || m == 2) {
        m += 12;
        y -= 1;
    }
    j = y / 100;
    k = y % 100;
    h = (d + 26 * (m + 1) / 10 + k + k / 4 + j / 4 + 5 * j) % 7;
    if (h < 2) {
        cout << h + 6 << endl;
    } else {
        cout << h - 1 << endl;
    }
    return 0;
}
