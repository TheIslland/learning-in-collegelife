/*************************************************************************
	> File Name: functional.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Sun Oct 27 18:36:09 2019
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<functional>
using namespace std;

int (*f2)(int, int);

function<int(int, int)> f1;

class test_class {
public:
    int operator() (int a, int b) {
        return a + b;
    }
};

int test_func(int a, int b) {
    return a + b;
}

auto test_lamba = [](int a, int b) -> int {
    return a - b;
};

int main() {
    test_class test_class_func;
    f1 = test_class_func;
    cout << f1(1, 2) << endl;
    f1 = test_func;
    cout << f1(1, 2) << endl;
    f1 = test_lamba;
    cout << f1(1, 2) << endl;
    f2 = test_lamba;
    cout << f2(1, 2) << endl;
    return 0;
}
