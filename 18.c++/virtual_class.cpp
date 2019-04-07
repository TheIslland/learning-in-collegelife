/*************************************************************************
	> File Name: virtual_class.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年03月28日 星期四 19时20分24秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
 
using namespace std;

class A {
public:
    A() { x = 1; }
    
    int x;
};

class B : public virtual A {
public:
    void adjustment1() {
        x = 2;
    }
    void cout1() {
        cout << x << endl;
    }
};

class C : public virtual A {
public:
    void adjustment2() {
        x = 3;
    }
    void cout2() {
        cout << x << endl;
    }
};

class D : public B, public C {
};

int main() {
    D d;
    d.adjustment1();
    d.cout1();
    d.cout2();
    return 0;
}
