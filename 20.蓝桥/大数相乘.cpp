/*************************************************************************
	> File Name: 大数相乘.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年03月23日 星期六 16时47分54秒
 ************************************************************************/
#include <bits/stdc++.h>
using namespace std;
long long int a[600] = {0};
long long int b[600] = {0};
long long int c[600] = {0};

void dashu() {
    c[0] = a[0] > b[0] ? a[0] : b[0];
    for (int i = a[0]; i > 0; i--) {
        int ind = 1, num = 0;
        for (int j = b[0]; j > 0; j--) {
            c[ind++] += a[i] * b[j];
        }
    }
}

int main() {
    string x, y;
    cin >> x >> y;
    a[0] = x.length();
    b[0] = y.length();
    for (int i = 1; i < a[0]; i++) {
        a[i] = x[i - 1] - '0';
    }
    for (int i = 1; i < b[0]; i++) {
        b[i] = x[i - 1] - '0';
    }
    dashu();
    for (int i = c[0]; i > 0; i--) {
        cout << c[i] << endl;
    }
    return 0;
}
