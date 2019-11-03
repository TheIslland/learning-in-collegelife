/*************************************************************************
	> File Name: 103整除问题.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Sat Nov  2 10:39:13 2019
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;
int main() {
    int a, b;
    cin >> a >> b;
    cout << (a % b ? "NO" : "YES") << endl;
    return 0;
}
