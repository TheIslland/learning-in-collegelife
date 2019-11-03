/*************************************************************************
	> File Name: 135x天后的日期.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Sun Nov  3 14:42:41 2019
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
int main() {
    int y, m, d, x, ans = 0;
    int a[3] = {0}, b[3] = {0};
    int month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    cin >> x;
    cin >> y >> m >> d;
    x += d;
    (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0)) && month[2]++;
    while (x > month[m]) {
        x -=  month[m];
        m++;
        if (m > 12) {
            y++;
            m -= 12;
            if (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0)) month[2] = 29;
            else month[2] = 28;
        }
    }
    cout << y << " " << m << " " << x;
    return 0;
}
