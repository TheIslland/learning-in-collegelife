/*************************************************************************
	> File Name: 126圆环面积.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Sun Nov  3 10:39:14 2019
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
int main() {
    double r1, r2;
    cin >> r1 >> r2;
    cout << setiosflags(ios::fixed) <<  setprecision(2) << 3.14 * (r1 * r1 - r2 * r2) << endl;
    return 0;
}
