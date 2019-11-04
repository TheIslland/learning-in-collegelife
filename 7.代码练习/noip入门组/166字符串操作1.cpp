/*************************************************************************
	> File Name: 166字符串操作1.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Mon Nov  4 16:29:24 2019
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
int main() {
    string a, b;
    int n;
    cin >> a >> n >> b;
    int len1 = a.length();
    if (len1 > 100) {
        cout << 100 << endl;
    } else {
        cout << len1 << endl;
    }
    a.insert(n - 1, b);
    cout << a << endl;
    int len2 = a.length();
    int ans = 0;
    for (int i = len2 - 1; i >= 0; i--) {
        ans++;
        if (a[i] == 'x') {
            cout << ans << endl;
            break;
        }
    }
    return 0;
}
