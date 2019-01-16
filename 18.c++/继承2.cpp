/*************************************************************************
	> File Name: 继承2.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年01月16日 星期三 10时25分19秒
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
    int b;
public:
    virtual void print() {
        cout << "hello" << endl;
    }
};

class Child : public Parent{
private:
    int c;
};
int main() {
    Parent A;
    Child B;
    cout << sizeof(A) << endl;
    cout << sizeof(B) << endl;
    return 0;
}
