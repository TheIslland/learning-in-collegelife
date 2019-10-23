/*************************************************************************
	> File Name: 486铺瓷砖.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Tue Oct 22 18:40:23 2019
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;
int a[1005] = {0};
int f(int n) {
    if (a[n] != 0) return a[n];
    if (n == 1) return 1;
    if (n == 2) return 3;
    a[n] = f(n - 1) % 12345 + (f(n - 2) % 12345 * 2) % 12345;
    return a[n];
}
int main() {
    int n;
    cin >> n;
    cout << f(n) % 12345 << endl;
    return 0;
}
