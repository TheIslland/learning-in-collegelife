/*************************************************************************
	> File Name: 107七的奇倍数.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Sat Nov  2 11:07:00 2019
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;
int main() {
    int n;
    cin >> n;
    cout << (n & 1 && n % 7 == 0 ? "YES" : "NO") << endl;
    return 0;
}
