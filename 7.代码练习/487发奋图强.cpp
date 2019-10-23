/*************************************************************************
	> File Name: 487发奋图强.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Tue Oct 22 19:00:32 2019
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;

int a[100] = {0};
int f(int n) {
    if (a[n] != 0) return a[n];
    if (n == 1) return 2;
    if (n == 2) return 2;
    a[n] = f(n - 1) + f(n -2);
    return a[n];
}
int main() {
    int n;
    cin >> n;
    cout << f(n) << endl;
    return 0;
}
