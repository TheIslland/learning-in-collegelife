/*************************************************************************
	> File Name: 453第k小正数.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Thu Nov  7 10:22:51 2019
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
    int n, m, k;
    int a[30005] = {0};
    int b[30005] = {0};
    cin >> n >> k;
    for (int i = 0 ; i < n; i++) {
        scanf("%d", &m);
        !b[m] && (b[m] = 1, a[++a[0]] = m);
    }
    sort(a + 1, a + a[0] + 1);
    if (k > a[0]) {
        cout << "NO RESULT" << endl;
    } else {
        cout << a[k] << endl;
    }
    return 0;
}
