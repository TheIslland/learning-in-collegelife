/*************************************************************************
	> File Name: 185斐波那契数列.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Tue Nov  5 01:13:53 2019
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
long long int a[31] = {1, 1, 1};
void init() {
    for (int i = 3; i < 31; i++) {
        a[i] = a[i - 1] + a[i - 2];
    }
}
int main() {
    init();
    int n;
    cin >> n;
    cout << a[n] << endl;
    return 0;
}
