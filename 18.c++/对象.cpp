/*************************************************************************
	> File Name: 继承.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年01月10日 星期四 20时01分28秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;
class Test {
private:
    int i;
    int j;
public:
    Test(int v1 = 0, int v2 = 0) {
        i = v1;
        j = v2;
    }
    int getI() {
        return i;
    }
    int getJ() {
        return j;
    }
    int add(int value) {
        return i + j + value;
    }
    ~Test() {
        
    }
};
class A {
    int a;
    int b;
    char c;
    double d;
public:
    void print() {
        cout << "a = " << a << endl;
        cout << "b = " << b << endl;
        cout << "c = " << c << endl;
        cout << "d = " << d << endl;
        
    }
};

struct B {
    int a;
    int b;
    char c;
    double d;
};

int main() {
    A a1;
    B b1;
    cout << sizeof(a1) << " " << sizeof(b1) << " " << endl;
    a1.print();
    B *p = reinterpret_cast<B *> (&a1);
    p->a = 100;
    p->b = 1000;
    p->c = 'c';
    p->d = 3.2;
    a1.print();
    p->a = 1234;
    p->b = 2345;
    p->c = 'd';
    p->d = 4.88998877;
    a1.print();
    return 0;
}
