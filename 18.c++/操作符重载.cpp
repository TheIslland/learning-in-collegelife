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
    double real;
    double imag;
public:
    Complex(int r = 0, int i = 0) {
        real = r;
        imag = i;
    }
    double getR() {
        return this->real;
    }
    double getI() {
        return this->imag;
    }
    friend Complex operator+(const Complex &c1, const Complex &c2);
    friend Complex operator-(const Complex &c1, const Complex &c2);
    friend Complex operator*(const Complex &c1, const Complex &c2);
    friend Complex operator/(const Complex &c1, const Complex &c2);
    friend bool operator==(const Complex &c1, const Complex &c2);
    friend bool operator!=(const Complex &c1, const Complex &c2);
    Complex& operator=(const Complex &c1) {
        if(this != &c1) { //不润徐自赋值　a = a
            this->real = c1.real;
            this->imag = c1.imag;
        }
        return *this;
    }
};

Complex operator+(const Complex &c1, const Complex &c2) {
    Complex ret;
    ret.real = c1.real + c2.real;
    ret.imag = c1.imag + c2.imag;
    return ret;
}
Complex operator-(const Complex &c1, const Complex &c2) {
    Complex ret;
    ret.real = c1.real - c2.real;
    ret.imag = c1.imag - c2.imag;
    return ret;
}
Complex operator*(const Complex &c1, const Complex &c2) {
    Complex ret;
    ret.real = c1.real * c2.real;
    ret.imag = c1.imag * c2.imag;
    return ret;
}
Complex operator/(const Complex &c1, const Complex &c2) {
    Complex ret;
    ret.real = (c1.real * c2.real + c1.imag * c2.imag) * 1.0 / (c2.real * c2.real + c2.imag * c2.imag) ;
    ret.imag = (c1.imag * c2.real - c1.real * c2.imag) * 1.0 / (c2.real * c2.real + c2.imag * c2.imag);
    return ret;
}
#define min 0.0000001
bool operator==(const Complex &c1, const Complex &c2) {
    if (c1.real - c2.real < min && c1.imag - c2.imag < min) return true;
    else return false;
}
bool operator!=(const Complex &c1, const Complex &c2) {
    if (c1.real - c2.real < min && c1.imag - c2.imag < min) return false;
    else return true;
}

int main() {
    Complex c1(1,2);
    Complex c2(3,4);
    Complex c3;
    c3 = c1 + c2;
    cout << c3.getR() << "+" << c3.getI() << "i" << endl;
    c3 = c1 - c2;
    cout << c3.getR();
    if (c3.getI() > 0) cout << "+";
    cout << c3.getI() << "i" << endl;
    c3 = c1 * c2;
    cout << c3.getR() << "*" << c3.getI() << "i" << endl;
    c3 = c1 / c2;
    cout << c3.getR() << "/" << c3.getI() << "i" << endl;
    if (c1 == c2)
    cout << "equal" << endl;
    if (c1 != c2) 
    cout << "not equal" << endl;
    return 0;
}
