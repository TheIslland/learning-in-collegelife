/*************************************************************************
	> File Name: 164艾斯的农场.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Mon Nov  4 15:00:49 2019
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    cout << n / m + (n % m == 0 ? 0 : 1) << endl;
    return 0;
}
