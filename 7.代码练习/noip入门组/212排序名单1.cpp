/*************************************************************************
	> File Name: 212排序名单1.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Wed Nov  6 20:49:30 2019
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
    string a[40];
    for (int i = 0; i < 10; i++) {
        cin >> a[i];
    }
    sort(a, a + 10);
    for (int i = 0; i < 10; i++) {
        cout << a[i] << endl;
    }
    return 0;
}
