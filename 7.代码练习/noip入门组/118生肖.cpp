/*************************************************************************
	> File Name: 118生肖.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Sat Nov  2 14:59:47 2019
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
int main() {
    string a[12] = {"rat", "ox", "tiger", "rabbit", "dargon", "snake", "horse", "sheep", "monkey", "rooster", "dog", "pig"};
    int year;
    cin >> year;
    cout << a[(year + 8) % 12] << endl;
    return 0;
}
