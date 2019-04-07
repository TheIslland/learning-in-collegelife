/*************************************************************************
	> File Name: 多继承.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年01月10日 星期四 20时49分58秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;
class A {
private:
    string name;
    int age;
    public:
    void print() {
        cout << name << " " << age << endl;
    }
};
class B : public A{};
class C : public A{};
class D : public B, public C {};

int main() {
    D d;
    B *pb = &d;
    C *pc = &d;
    void *pbb = pb;
    void *pcc = pc;
    d.B::print();
    d.C::print();
    if (pbb == pcc) {
        cout << "point the same address!" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}
