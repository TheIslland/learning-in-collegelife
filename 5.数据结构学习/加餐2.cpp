/*************************************************************************
	> File Name: 加餐2.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年02月20日 星期三 10时51分42秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>

class A {
public:
    virtual void func();
};

class B : public A {
public: 
    int num;
};

class C : public A {
public:
    int num;
};

int main() {
    srand(time(0));
    A *a;
    B b;
    C c;
    if (rand() % 2) {
        a = &b;
    } else {
        a = &c;
    }
    dynamic_cast<B *>(a);
    return 0;
}
