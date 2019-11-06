/*************************************************************************
	> File Name: 217分数线.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Wed Nov  6 22:46:07 2019
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
    int n, m, ans = 0;
    int a[100005] = {0};
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    m = n / 2;
    for (int i = 0; i < n; i++) {
        a[i] >= a[m] && ans++;
    }
    cout << a[m] << " " << ans << endl;
    return 0;
}
