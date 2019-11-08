/*************************************************************************
	> File Name: 57有趣的序列.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Thu Nov  7 14:01:59 2019
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
    string str = "";
    ll a = 1;
    while ((int)str.length() < 1000001) {
        str += to_string(a);
        a++;
    }
    int x, y, z;
    cin >> x >> y >> z;
    cout << str[x - 1] * str[y - 1] * str[z - 1] << endl;
    return 0;
}
