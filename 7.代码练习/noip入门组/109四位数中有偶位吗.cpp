/*************************************************************************
	> File Name: 109四位数中有偶位吗.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Sat Nov  2 11:20:09 2019
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;
int main() {
    int n, flag = 0;
    cin >> n;
    while (n && !flag) {
        n % 10 & 1 ? n /= 10 : flag = 1; 
    }
    cout << (flag ? "YES" : "NO") << endl;
    return 0;
}
