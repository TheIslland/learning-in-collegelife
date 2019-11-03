/*************************************************************************
	> File Name: 114他的名字.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Sat Nov  2 13:20:08 2019
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
int main() {
    char x;
    string a;
    cin >> x;
    switch(x) {
        case 'h': a = "He"; break;
        case 'l': a = "Li"; break;
        case 'c': a = "Cao"; break;
        case 'd': a = "Duan"; break;
        case 'w': a = "Wang"; break;
        default: a = "Not Here";
    }
    cout << a << endl;
    return 0;
}
