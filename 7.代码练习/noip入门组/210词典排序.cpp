/*************************************************************************
	> File Name: 210词典排序.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Wed Nov  6 20:42:22 2019
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
    string a[30];
    cin >> n;
    for (int i = 0 ; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    for (int i = 0; i < n; i++) {
        cout << a[i] << (i < n -1 ? " " : "");
    }
    return 0; 
}
