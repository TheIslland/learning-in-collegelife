/*************************************************************************
	> File Name: 133输出乘法表.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Sun Nov  3 14:14:56 2019
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            cout << i << "*" << j << "="  << i * j << (j < n ? "\t" : "\n");
        }
    }
    return 0;
}
