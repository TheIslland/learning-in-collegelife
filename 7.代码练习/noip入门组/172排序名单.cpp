/*************************************************************************
	> File Name: 172排序名单.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Mon Nov  4 23:29:47 2019
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<iomanip>
#include<string>
using namespace std;
int main() {
    string name[10];
    for (int i = 0; i < 10; i++) {
        cin >> name[i];
    }
    sort(name, name + 10);
    for (int i = 0; i< 10; i++) {
        cout << name[i] << endl; 
    }
    return 0;
}
