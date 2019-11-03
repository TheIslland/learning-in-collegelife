/*************************************************************************
	> File Name: 119昨天和明天.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Sat Nov  2 13:11:55 2019
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
int main() {
    int y, m, d, ans = 0;
    int a[3] = {0}, b[3] = {0};
    int month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    cin >> y >> m >> d;
    a[0] = b[0] = y;
    a[1] = b[1] = m;
    a[2] = b[2] = d;
    (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0)) && month[2]++;
    if (d - 1 <= 0) {
        if (m - 1 <= 0) {
            a[0] -= 1;
            a[1] = 12;
            a[2] = 31;
        } else {
            a[1] -= 1;
            a[2] = month[a[1]];
        }
    } else {
        a[2] -= 1;
    } 
    if (d + 1 > month[b[1]]){
        if (m + 1 > 12) {
            b[0] += 1;
            b[1] = 1;
            b[2] = 1;
        } else {
            b[1] += 1;
            b[2] = 1;
        }
    } else {
        b[2] += 1;
    }
    cout << a[0] << " " << a[1] << " " << a[2] << endl;
    cout << b[0] << " " << b[1] << " " << b[2] << endl;
    return 0;
}
