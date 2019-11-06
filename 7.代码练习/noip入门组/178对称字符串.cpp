/*************************************************************************
	> File Name: 178对称字符串.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Tue Nov  5 00:39:58 2019
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<iomanip>
#include<cstring>
#include<cstdio>
using namespace std;
char str[2][5000000] = {"A", "A"};
int main() {
    int n;
    char x[10] = "A";
    cin >> n;
    for (int i = 1; i < n; i++) {
        strcpy(str[1], str[0]);
        x[0]++;
        //cout << "str[" << i << "] = " << str[i - 1] << endl;
        int len = strlen(str[0]);
        str[1][len] = x[0];
        strcpy(str[1] + len + 1, str[0]);
        strcpy(str[0], str[1]);
    }
    cout << str[1] << endl;
    return 0;
}
