/*************************************************************************
	> File Name: 多重继承.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年01月10日 星期四 19时03分02秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <string>
using std::cin;
using std::cout;
using std::endl;
class A {
private:
    int i;
public:
    A(int v = 0) {
        i = v;
    }
    int add() {
        return i + 1;
    }

    int add(int a, int b, int c) {
        return i + a + b + c;
    }
    int get() {
        cout << "A::i = " << i << endl;
        return i;
    }
};

class B : public A {
public:
    int i;
public:
    B(int v) : A(0) {
        i = v;
    }
    /*int get() {
        return i;
    }*/
    int add(int a) {
        return i + a;
    }

    int add(int a, int b, int c) {
        return i + a + b + c * c;
    }
};
int main() {
    B b(3);
    A a;
    cout << b.A::add() << endl;
    cout << b.add(1, 2, 3) << endl;
    cout << b.get() << endl;
    /*cout << b.i << endl;
    cout << sizeof(a) << endl; //A类整形占了四个字节
    cout << sizeof(b) << endl; //B类也是一个整形占了四个字节但Ｂ类中包含Ａ类所以大小为：Ｂ＋ A = 4 + 4 = 8
    b.A::i = 100000;
    cout << b.A::i << endl;*/
    return 0;
}
