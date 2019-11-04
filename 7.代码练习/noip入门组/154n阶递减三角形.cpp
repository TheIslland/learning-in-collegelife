/*************************************************************************
	> File Name: 154n阶递减三角形.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Sun Nov  3 23:24:43 2019
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
int main() {
    int n;
    cin >> n;
    for (int i = n; i > 0; i--) {
        for (int j = i; j > 0; j--) {
            cout << j  << (j > 1 ? " " : "");
        }
        cout << endl;
    }
    return 0;
}
