/*************************************************************************
	> File Name: 169密码翻译.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Mon Nov  4 21:49:24 2019
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<iomanip>
#include<string>
#include<cstring>
using namespace std;
int main() {
    int a[200] = {0};
    int n, x;
    char m;
    string str;
    cin >> n;
    getchar();
    for (int i = 0; i < n; i++) {
        cin >> m;
        getchar();
        cin >> x;
        a[m] = x;
    }
    getchar();
    cin >> str;
    int len = str.length();
    // transform(str.begin(), str.end(), str.begin(), ::toupper);
    int ans = 0;
    for (int i = 0 ;i < len; i++) {
        ans += a[str[i]];
    }
    cout << ans << endl;
    return 0;
}
