/*************************************************************************
	> File Name: 131n个数的极差.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Sun Nov  3 13:21:08 2019
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
int main() {
    int n, m, max = 0, min = 10005;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> m;
        if (m > max) max = m;
        if (m < min) min = m;
    }
    cout << max - min << endl;
    return 0;
}
