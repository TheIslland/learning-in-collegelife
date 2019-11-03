/*************************************************************************
	> File Name: 120日期合法性.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Sat Nov  2 15:50:41 2019
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
int main() {
    int y, m, d;
    int month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    cin >> y >> m >> d;
    (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0)) && month[2]++;
    if (y <= 0 || m <= 0 || m > 12 || d <= 0 || d > month[m]) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }
    return 0;
}
