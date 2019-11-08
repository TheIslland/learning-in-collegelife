/*************************************************************************
	> File Name: 459学生信息.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Thu Nov  7 09:22:27 2019
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
    string name, sex;
    int old;
    double h;
    cin >> name >> sex >> old >> h;
    cout << name << " " << sex << " " << old << " " << setiosflags(ios::fixed) << setprecision(1) << h << endl;
    return 0;
}
