/*************************************************************************
	> File Name: 140输出字母菱形.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Sun Nov  3 17:24:29 2019
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
int main() {
    int n;
    char x = 'A';
    cin >> n;
    for (int i = 1; i <= n - 1; i++) {
        for (int j = 0; j < n - i; j++) cout << " ";
        int m = 1 + 2 * (i - 1);
        for (int j = 0; j < m; j++) {
            cout << (char)(x + i - 1) << (j < m - 1? "" : "\n");
        }
    }
    x += n - 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) cout << " ";
        int m = 1 + (n - i - 1) * 2;
        for (int j = 0; j < m; j++) {
            cout << (char)(x - i) << (j < m - 1 ? "" : "\n");
        }
    }
    return 0;
}
