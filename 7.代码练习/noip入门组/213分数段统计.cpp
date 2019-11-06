/*************************************************************************
	> File Name: 213分数段统计.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Wed Nov  6 22:03:36 2019
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
bool cmp(int a, int b) {
    return a > b;
}
int main() {
    int b[7] = {0};
    int a[35] = {0};
    int n, m;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> m;
        a[i] = m;
        m == 100 && b[1]++;
        (m >= 90 && m <= 99) && b[2]++;
        (m >= 80 && m <= 89) && b[3]++;
        (m >= 70 && m <= 79) && b[4]++;
        (m >= 60 && m <= 69) && b[5]++;
        m < 60 && b[6]++;
    }
    sort(a, a + n, cmp);
    for (int i = 0;  i < n; i++) {
        cout << a[i] << endl;
    }
    for (int i = 1; i < 7; i++) {
        cout << b[i] << (i < 6 ? " " : "");
    }
    return 0;
}
