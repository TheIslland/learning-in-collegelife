/*************************************************************************
	> File Name: 98计算圆柱体的体积.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Fri Nov  1 20:41:56 2019
 ************************************************************************/

#include<iostream>
#include<iomanip>
#include<algorithm>
using namespace std;
int main() {
    double r, h;
    cin >> r >> h;
    cout << setiosflags(ios::fixed) << setprecision(2) << r * r * 3.14 << endl << r * r * 3.14 * h << endl;
    return 0;
}
