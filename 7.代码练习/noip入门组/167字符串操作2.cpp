/*************************************************************************
	> File Name: 167字符串操作2.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Mon Nov  4 16:45:12 2019
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
    cout << len1 << endl;
    int ans = 0;
    for (int i = 0; i <= len1 - 1; i++) {
        ans++;
        if (a[i] == 'a') {
            cout << ans << endl;
            break;
        }
    }
    a.insert(n - 1, b);
    cout << a << endl;
    return 0;
}
