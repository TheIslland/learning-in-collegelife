/*************************************************************************
	> File Name: 117回文数.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Sat Nov  2 14:56:39 2019
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
int main() {
    int a;
    cin >> a;
    int b = a, c = 0;
    while (a) {
        c = c * 10 + a % 10;
        a /= 10;
    }
    cout << (b == c ? "YES" : "NO") << endl;
    return 0;
}
