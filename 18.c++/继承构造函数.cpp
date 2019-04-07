/*************************************************************************
	> File Name: 继承构造函数.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年01月10日 星期四 18时19分21秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;
class Parent {
protected:
    int i;
public:
    Parent(int v = 0) {
        i = v;
        cout << "parent i = " << i << endl; 
    }
   /* Parent() {
        cout << "Parent()" << endl;
    }*/
};
class Child : public Parent {
public:
    Child() : Parent(5) {
        cout << "Child()" << endl;
    }
    int getI() {
        return i;
    }
};
class A {
public:
    A() {
        cout << "A()" << endl;
    }
};
class B : public A {
public:
    B() {
        cout << "B()" << endl;
    }   
};
class C {
public:
    C() {
        cout << "C()" << endl;
    }
};
class D : public C {
private:
    B b;
public:
    D() {
        cout << "D()" << endl;
    }
};

//默认调用方式: 要求父类构造函数必须是无参或带默认参数的构造函数
int main() {
    D d;
    Child c;
    cout << c.getI() << endl;
    return 0;
}
