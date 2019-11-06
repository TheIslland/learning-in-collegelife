/*************************************************************************
	> File Name: 211颠倒字符串排序.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Wed Nov  6 20:44:48 2019
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
    int n;
    string a[40];
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        reverse(a[i].begin(), a[i].end());
    }
    sort(a, a + n);
    for (int i = 0; i < n; i++) {
        cout << a[i] << endl;
    }
    return 0;
}
