/*************************************************************************
	> File Name: 多态.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年01月16日 星期三 09时33分39秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

class Parent {
public:
    virtual void say() { //在父类与子类函数同名时，可以在父类同名函数前加ｖｉｔｕｒａｌ来实现多态，子类中的同名函数会编程虚函数
        cout << "I'm Parent" << endl;
    }
};

class Child : public Parent {
public:
    virtual void say() {
        cout << "I'm Chils" << endl;
    }
};

void how_to_say(Parent *p) {
    p->say();
}

int main() {
    Parent p;
    Child c;
    how_to_say(&p);
    how_to_say(&c);
    return 0;
}
