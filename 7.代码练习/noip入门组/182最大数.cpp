/*************************************************************************
	> File Name: 182最大数.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Tue Nov  5 01:01:45 2019
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
int main() {
    long long int n, m, max = -1;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> m;
        if (m > max) max = m;
    }
    cout << max << endl;
    return 0;
}
