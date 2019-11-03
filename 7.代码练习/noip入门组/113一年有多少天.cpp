/*************************************************************************
	> File Name: 113一年有多少天.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Sat Nov  2 13:11:55 2019
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
int main() {
    int y, m, ans = 0;
    int month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    cin >> y >> m;
    (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0)) && month[1]++;
    cout << month[m - 1] << endl;
    return 0;
}
