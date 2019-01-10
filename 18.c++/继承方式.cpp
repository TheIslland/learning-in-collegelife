/*************************************************************************
	> File Name: 继承方式.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年01月10日 星期四 18时05分13秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

class Parent {
private:
    int a;
public:
    int b;
    void set (int v1, int v2, int v3) {
        a = v1;
        b = v2;
        c = v3;
    }
protected:
    int c;
};
//三种继承方式,在其他语言中private与protected已经去掉因为过于复杂
class Child1 : public Parent {
public:
    void print() {
        cout << "a = " << a << endl; //无法访问私有属性
        cout << "b = " << b << endl;
        cout << "c = " << c << endl;
    }
};
class Child2 : private Parent {
public:
    void print() {
        cout << "a = " << a << endl;
        cout << "b = " << b << endl;
        cout << "c = " << c << endl;
    }

};
class Child3 : protected Parent {
public:
    void print() {
        cout << "a = " << a << endl;
        cout << "b = " << b << endl;
        cout << "c = " << c << endl;
    }
};

class Test : public Child3 {
    void set (int v) {
        b = v;
    }
};
int main() {
    Child2 c;
    Child3 c1;
    c2.b = 100; //私有继承自父类，所以报错
    return 0;
}
