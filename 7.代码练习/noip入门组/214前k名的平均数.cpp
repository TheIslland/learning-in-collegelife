/*************************************************************************
	> File Name: 214前k名的平均数.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Wed Nov  6 22:17:32 2019
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
    int n, k, sum = 0;
    int a[35] = {0};
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> k;
    sort(a, a + n, cmp);
    for (int i = 0; i < k; i++) {
        sum += a[i];
    }
    cout << setiosflags(ios::fixed) << setprecision(2) << sum * 1.0 / k << endl;
    return 0;
}
