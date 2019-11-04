/*************************************************************************
	> File Name: 139输出A字菱形.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Sun Nov  3 16:05:21 2019
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n - 1; i++) {
        for (int j = 0; j < n - i; j++) cout << " ";
        for (int j = 0; j < 2 * i; j++) {
            cout << "A" << (j < 2 * i - 1 ? "" : "\n");
        }
    } 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) cout << " ";
        for (int j = 0; j < (n - i) * 2; j++) {
            cout << "A" << (j < (n - i) * 2 - 1 ? "" : "\n");
        }
    }
    return 0;
}
