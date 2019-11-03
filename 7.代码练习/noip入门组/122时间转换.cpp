/*************************************************************************
	> File Name: 122时间转换.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Sat Nov  2 17:25:46 2019
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
int main() {
    int h, m, s, t; 
    h = m = s = 0;
    cin >> t;
    s += t;
    m += s / 60;
    s %= 60;
    int x = m / 60 % 24;
    m %= 60;
    if (x >= 0 && x < 12) {
        h = 1;
    } else if (x >= 12 && x < 13){
        h = 2;
        x = 12;
    } else {
        h = 3;
        x -= 12;
    }
    cout << setw(2) << setfill('0') << x << ':' << setw(2) << setfill('0') << m << ':' << setw(2) << setfill('0') << s;
    if (h == 1) {
        cout << " am" << endl;
    } else if (h == 2) {
        cout << " midnoon" << endl;
    } else {
        cout << " pm" << endl;
    }
    return 0; 
}
