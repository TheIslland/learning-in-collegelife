/*************************************************************************
	> File Name: 127高利贷.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Sun Nov  3 10:45:34 2019
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<iomanip>
#include<cmath>
using namespace std;
int main() {
    int x, n;
    cin >> x >> n;
    cout << (int)(x * pow(1.06, n)) << endl;
    return 0;
}
