/*************************************************************************
	> File Name: 463桌面窗体重叠.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Thu Nov  7 08:49:31 2019
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
    int a[4] = {0};
    int b[4] = {0};
    for (int i = 0; i < 4; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < 4; i++) {
        cin >> b[i];
    }
    if (a[0] > b[1] || b[0] > a[1] || a[2] > b[3] || b[2] > a[3]) {
        cout << 0 << endl;
    } else {
        cout << ((a[1] < b[1] ? a[1] : b[1]) - (a[0] > b[0] ? a[0] : b[0])) * ((a[3] < b[3] ? a[3] : b[3]) - (a[2] > b[2] ? a[2] : b[2])) << endl;
    }
    return 0;
}
