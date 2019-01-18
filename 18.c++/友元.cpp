/*************************************************************************
	> File Name: 操作符重载.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年01月18日 星期五 16时06分47秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
 
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::queue;
using std::stack;
class Test {
private:
    int i;
public:
    Test(int v = 0) {
        i = v;
    }
    friend int get(Test &t);
};
int get(Test &t) {
    return t.i;
}
class C {
private:
    int c;
public:
    C(int v = 0) {
        c = v;
    }
    friend class B;
};

class B {
private:
    int b;
public:
    B(int v = 0) {
        b = v;
    }
    int getc(C &c1) {
        return c1.c;
    }
    friend class A;
};

class A{
public:
    int getB(B &b1) {
        return b1.b;
    }
    int getC(B &b2, C &c2) {
        return b2.getc(c2);
    }
};
int main() {
    Test t(10);
    cout << get(t) << endl;
    C c(10);
    B b(5);
    A a;
    cout << a.getB(b) << endl;
    cout << a.getC(b, c) << endl;
    return 0;
}
