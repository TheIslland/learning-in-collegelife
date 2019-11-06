/*************************************************************************
	> File Name: 216获取姓名并排序.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Wed Nov  6 22:38:42 2019
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
    string a[105];
    string temp;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        a[i] = temp.substr(3, temp.length());
    }
    sort(a, a + n);
    for (int i = 0; i < n; i++) {
        cout << a[i] << endl;
    }
    return 0;
}
