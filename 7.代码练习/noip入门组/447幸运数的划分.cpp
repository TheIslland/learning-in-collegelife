/*************************************************************************
	> File Name: 447幸运数的划分.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Thu Nov  7 01:40:58 2019
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<iomanip>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
typedef long long ll;
using namespace std;
int main() {
    int n, m, judg = 0;
    cin >> n;
    while (n && !judg) {
        if (n % 10 == 4 || n % 10 == 7) {
            cout << "YES" << endl;
            judg = 1;
        }
    }
    if(!judg) cout << "NO" << endl;
    return 0;
}
