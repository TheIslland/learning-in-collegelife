/*************************************************************************
	> File Name: 94计算BMI.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Fri Nov  1 20:13:10 2019
 ************************************************************************/

#include<iostream>
#include<iomanip>
#include<algorithm>
using namespace std;
int main() {
    double w, h;
    cin >> w >> h;
    cout << setiosflags(ios::fixed) << setprecision(2) << w / (h * h) << endl;
    return 0;
}
