/*************************************************************************
	> File Name: 168规范化名字.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Mon Nov  4 21:11:06 2019
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<iomanip>
#include<string>
using namespace std;
int main() {
    string str[101];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> str[i];
        string s1 = str[i].substr(0, 1);
        string s2 = str[i].substr(1, str[i].length());
        transform(s1.begin(),s1.end(),s1.begin(),::toupper);
        transform(s2.begin(),s2.end(),s2.begin(),::tolower);
        str[i] = s1 + s2;
    }
    sort(str, str + n);
    for (int i = 0; i < n; i++) {
        cout << (string)str[i] << endl;
    }
    return 0;
}
