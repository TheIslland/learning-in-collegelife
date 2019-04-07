/*************************************************************************
	> File Name: 析构函数.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年01月03日 星期四 18时11分38秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <string>

using std::cin;
using std::cout;
using std::endl;

class Value {
private:
    int i;
public:
    Value(int v) : i(v) {
        cout << "Value :: i" << i << endl;
    }
};

class Test {
private:
    const int i;
    int a;
    Value v1;
public:
    Test(int v1, int v2, int v3);
    int getI() {
        return i;
    }
    ~Test() {
        cout << "success" << endl;
    }
};

Test::Test(int v1, int v2, int v3) : i(v1), a(v2) , v1(v3) {
    cout << "i = " << i << endl;
    cout << "a = " << a << endl;
}
int main() {
    Test t(10, 100, 200);
    return 0;
}
