/*************************************************************************
	> File Name: 138输出A字三角形.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Sun Nov  3 15:46:43 2019
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int m = 2 * (n - i);
        for (int j = 0; j < m; j++) {
            cout << "A" << (j < m - 1 ? "" : "\n");
        }
    }
    return 0;
}
