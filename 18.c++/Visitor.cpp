/*************************************************************************
	> File Name: 7.visitor.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2019年03月23日 星期六 09时25分46秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>

using namespace std;

class B;
class C;
class D;
class E;
class F;
class G;

class A {
public:
    class Visitor {
    public:
        virtual void Visit(B *) = 0;
        virtual void Visit(C *) = 0;
        virtual void Visit(D *) = 0;
        virtual void Visit(E *) = 0;
        virtual void Visit(F *) = 0;
        virtual void Visit(G *) = 0;
    };
    virtual void test() = 0;
    virtual void Accept(Visitor *vis) = 0;
    virtual ~A() {
        cout << "A" << endl;
    }
};

class B : public A {
public:
    virtual void test() {}
    virtual void Accept(Visitor *vis) {
        vis->Visit(this);
    }
    ~B() {
        cout << "B" << endl;
    }
};

class C : public A {
public:
    virtual void test() {}
    virtual void Accept(Visitor *vis) {
        vis->Visit(this);
    }
    ~C() {
        cout << "C" << endl;
    }
};
class D : public A {
public:
    virtual void test() {}
    virtual void Accept(Visitor *vis) {
        vis->Visit(this);
    }
    ~D() {
        cout << "D" << endl;
    }
};
class E : public A {
public:
    virtual void test() {}
    virtual void Accept(Visitor *vis) {
        vis->Visit(this);
    }
    ~E() {
        cout << "E" << endl;
    }
};
class F : public A {
public:
    virtual void test() {}
    virtual void Accept(Visitor *vis) {
        vis->Visit(this);
    }
    ~F() {
        cout << "F" << endl;
    }
};
class G : public A {
public:
    virtual void test() {}
    virtual void Accept(Visitor *vis) {
        vis->Visit(this);
    }
    ~G() {
        cout << "G" << endl;
    }
};

class CoutVisitor : public A::Visitor {
    void Visit(B *obj) {
        cout << "Class B" << endl;
    }
    void Visit(C *obj) {
        cout << "Class C" << endl;
    }
    void Visit(D *obj) {
        cout << "Class D" << endl;
    }
    void Visit(E *obj) {
        cout << "Class E" << endl;
    }
    void Visit(F *obj) {
        cout << "Class F" << endl;
    }
    void Visit(G *obj) {
        cout << "Class G" << endl;
    }

};
class NumVisitor : public A::Visitor {
    void Visit(B *obj) {
        cout << "Class B = 2" << endl;
    }
    void Visit(C *obj) {
        cout << "Class C = 4" << endl;
    }
    void Visit(D *obj) {
        cout << "Class D = 6" << endl;
    }
    void Visit(E *obj) {
        cout << "Class E = 8" << endl;
    }
    void Visit(F *obj) {
        cout << "Class F = 10" << endl;
    }
    void Visit(G *obj) {
        cout << "Class G = 12" << endl;
    }
};
int main() {
    srand(time(0));
    A *p;
    switch(rand() % 5) {
        case 0: p = new B(); break;
        case 1: p = new C(); break;
        case 2: p = new D(); break;
        case 3: p = new E(); break;
        case 4: p = new F(); break;
        
    }  
    CoutVisitor c_vis;
    NumVisitor n_vis;
    p->Accept(&c_vis);
    return 0;
}
