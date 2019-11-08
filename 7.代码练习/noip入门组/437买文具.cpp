/*************************************************************************
	> File Name: 437买文具.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Thu Nov  7 00:13:11 2019
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
    int a, b;
    cin >> a >> b;
    double c = a * 10 + b;
    cout << (int)(c / 26) << endl;
    return 0;
}
