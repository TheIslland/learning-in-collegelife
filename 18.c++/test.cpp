/*************************************************************************
	> File Name: test.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2018年12月28日 星期五 02时34分25秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main() {
    int a = 5;
    bool b = false;
    cout << sizeof(b) << endl;
    cout << a << " " << b << endl;
    b++;
    cout << a << " " << b << endl;
    a = b + a;
    cout << a << " " << b << endl;

    return 0;
}
