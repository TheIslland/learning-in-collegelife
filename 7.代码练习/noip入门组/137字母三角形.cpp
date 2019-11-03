/*************************************************************************
	> File Name: 137字母三角形.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Sun Nov  3 15:11:04 2019
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<iomanip>
#include<cstdio>
using namespace std;
int main() {
    int n, j = 0;
    char x = 'A';
    cin >> n;
    for (int i = n; i >= 0; i--) {
        for (j = 0; j < i; j++) {
            cout << x++ << (j < i - 1 ?  "" : "\n") ;
        }
    }
    return 0;
}
