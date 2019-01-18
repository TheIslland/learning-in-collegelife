/*************************************************************************
	> File Name: 操作符重载.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年01月18日 星期五 16时06分47秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

class Complex {
private: 
    int real;
    int imag;
public:
    Complex(int r = 0, int i = 0) {
        real = r;
        imag = i;
    }
    int getR() {
        return this->real;
    }
    int getI() {
        return this->imag;
    }
    friend Complex operator+(const Complex &c1, const Complex &c2);
};

Complex operator+(const Complex &c1, const Complex &c2) {
    Complex ret;
    ret.real = c1.real + c2.real;
    ret.imag = c1.imag + c2.imag;
    return ret;
}

int main() {
    Complex c1(1,2);
    Complex c2(3,4);
    Complex c3;
    //c3 = c1 + c2;
    c3 = operator+(c1, c2);
    cout << c3.getR() << "+" << c3.getI() << "i" << endl;
    return 0;
}
