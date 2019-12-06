/*************************************************************************
	> File Name: 继承.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Sat Oct 26 14:52:37 2019
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;
class Animal {
public :
    Animal(const string &name) : __name (name) {}
    virtual void run() {
        cout << "I dont know how can run" << endl;
    }
    ~Animal() {};
protected :
    string __name;
};
class Cat : public Animal {
public:
    Cat() :Animal("cat") {}
    void run() override {
        cout << "I can run  with four legs" << endl;
    }
};
int main() {
    Cat a;
    Animal &b = a;
    Animal *c = &a;
    a.run();
    b.run();
    c->run();
    return 0;
}
