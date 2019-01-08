/*************************************************************************
	> File Name: c++返回值优化.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年01月08日 星期二 18时16分18秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <string>
using std::cin;
using std::cout;
using std::endl;

class Test {
private:
    int i;
public:
    Test(int v) {
        i = v;
        cout << "Test(int v) : i = " << i << endl;
    }
    Test() {
        //Test(100);
        //第２３行会产生一个临时对象（幂名），生命周期只有一行要尽量避免使用
        i = 0;
        cout << "Test() : i = " << i << endl;
    }
    Test(const Test &t) {
        i = t.i; // ?
        cout << "Test(const Test &t) : i = " << i << endl;
    }
    void printI() {
        cout << "i = " << i << endl;
    }
};

void func1(Test t) {
    return ;
}

Test func2() {
    return Test(100); //生成临时对象返回时发生一次拷贝
    //return Test(100);
}

int main() {
    Test t = Test(100); //等价于t = 100
    t.printI();
    Test t1 = func2(); // 发生一次拷贝
    func1(t); //有拷贝构造函数调用
    Test t2[3] = {Test(1). Test(2), Test(3)}; // 将会调用三次拷贝构造函数
    Test t3[3] = {1, 2, 3}; //返回值优化后相当于
    return 0;
}
