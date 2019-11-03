/*************************************************************************
	> File Name: 104数字之中有9吗.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Sat Nov  2 10:42:04 2019
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;
int main() {
    int a, flag = 0;
    cin >> a;
    while (a && !flag) {
        flag = (a % 10 == 9 ? 1 : 0);
        a /= 10;
    }
    cout << (flag ? "YES" : "NO") << endl; 
    return 0;
}
