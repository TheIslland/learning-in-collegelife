/*************************************************************************
	> File Name: 取数位I.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Fri Nov  1 19:46:12 2019
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;
int main() {
    int a;
    cin >> a;
    cout << a / 10 % 10 << endl << a % 10 << endl;
    return 0;
}
