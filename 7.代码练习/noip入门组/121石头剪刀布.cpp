/*************************************************************************
	> File Name: 121石头剪刀布.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Sat Nov  2 16:11:49 2019
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
int main() {
    char a, b;
    cin >> a >> b;
    if (a == 'O' && b == 'Y') {
        cout << "MING" << endl;
    } else if (a == 'Y' && b == 'O') {
        cout << "LI" << endl;
    } else if (a == 'Y' && b == 'H') {
        cout << "MING" << endl;
    } else if (a == 'H' && b == 'Y') {
        cout << "LI" << endl;
    } else if (a == 'H' && b == 'O') {
        cout << "MING" << endl;
    } else if (a == 'O' && b == 'H') {
        cout << "LI" << endl;
    } else {
        cout << "TIE" << endl;
    }
    return 0;
}
