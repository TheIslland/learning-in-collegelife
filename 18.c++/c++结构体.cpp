/*************************************************************************
	> File Name: c++结构体.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年01月08日 星期二 18时10分06秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <string>
using std::cin;
using std::cout;
using std::endl;

class A {
    int a;
    int b;
    int getA() {
        return a;
    }
    int getB() {
        return b;
    }
};
struct B {
    int a;
    int b;
    int getA() {
        return a;
    }
    int getB() {
        return b;
    }
};

int main() {
    A aa;
    B bb;
    aa.a = 10;
    aa.b = 100;
    cout << aa.getA() << endl;
    cout << aa.getB() << endl;
    bb.a = 100;
    bb.b = 10;
    cout << bb.getA() << endl;
    cout << bb.getB() << endl;
    return 0;
}
