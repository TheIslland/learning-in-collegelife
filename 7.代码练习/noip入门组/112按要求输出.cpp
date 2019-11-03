/*************************************************************************
	> File Name: 112按要求输出.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Sat Nov  2 13:00:48 2019
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
int main() {
    char flags;
    cin >> flags;
    if (flags == 'a') {
        cout << "It is good" << endl;
    } else if (flags == 'b') {
        cout << "OMG" << endl;
    } else {
        cout << "Yes!" << endl;
    }
    return 0;
}
