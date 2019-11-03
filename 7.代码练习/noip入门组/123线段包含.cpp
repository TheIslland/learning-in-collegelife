/*************************************************************************
	> File Name: 123线段包含.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Sat Nov  2 18:04:21 2019
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if ((a <= c && b >= d) || (c <= a && d >= b)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}
