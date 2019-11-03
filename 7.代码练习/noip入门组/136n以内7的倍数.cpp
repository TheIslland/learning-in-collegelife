/*************************************************************************
	> File Name: 136n以内7的倍数.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Sun Nov  3 15:08:46 2019
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
int main() {
    int n;
    cin >> n;
    for (int i = 7; i <= n; i += 7) {
        cout << i << endl;
    }
    return 0;
}
