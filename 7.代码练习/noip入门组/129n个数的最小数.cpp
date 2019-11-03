/*************************************************************************
	> File Name: 129n个数的最小数.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Sun Nov  3 11:26:49 2019
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
int main() {
    int n, m, min = 10005;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> m;
        m < min ? min = m:min;
    }
    cout << min << endl;
    return 0;
}
