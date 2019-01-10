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
    void say() {
        cout << "hellow i'm a" << endl;
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
    //因为子类中有add所以隐藏了父类的add
    int add(int a) {
        return i + a;
    }

    int add(int a, int b, int c) {
        return i + a + b + c * c;
    }
    void say() {
        cout << "hellow i'm b" << endl;
    }
};

void how_to_say(A *p) { //父子兼容加同名属性问题，儿子未表达, 可以通过添加vitual解决。遇到父子兼容加同名属性造成问题的原因：因为编译器编译器为保证安全性同一调用父类
    p->say();
    return ;
}

int main() {
    B b(3);
    A a(100);
    cout << b.A::add() << endl;
    cout << b.add(1, 2, 3) << endl;
    cout << b.get() << endl;
    /*cout << b.i << endl;
    cout << sizeof(a) << endl; //A类整形占了四个字节
    cout << sizeof(b) << endl; //B类也是一个整形占了四个字节但Ｂ类中包含Ａ类所以大小为：Ｂ＋ A = 4 + 4 = 8
    b.A::i = 100000;
    cout << b.A::i << endl;*/
    how_to_say(&a);
    how_to_say(&b);
    return 0;
}
