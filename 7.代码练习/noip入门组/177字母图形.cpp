/*************************************************************************
	> File Name: 177字母图形.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Tue Nov  5 00:29:33 2019
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<iomanip>
#include<cstring>
#include<cstdlib>
using namespace std;
int main() {
    string str;
    cin >> str;
    int len = str.length();
    cout << str << endl;
    for (int i = 1; i < len; i++) {
        string str1 = str.substr(str.length() - 2, str.length());
        string str2 = str.substr(0, str.length() - 2);
        str = str1 + str2;
        cout << str << endl;
    }
    return 0;
}
