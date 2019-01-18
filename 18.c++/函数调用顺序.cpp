/*************************************************************************
	> File Name: 重载函数模板.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年01月18日 星期五 09时07分47秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
 
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::queue;
using std::stack;
void add(int a, int b) {
    cout << "void add(int a, int b)" << endl;
    cout << a + b << endl;
    return;
}

void add(int a) {
    cout << "void add(int)" << endl;
}

template <typename T>
void add(T a, T b) {
    cout << "void add(T a, T b)" << endl;
    cout << a + b << endl;
    return ;
}

void add(...) {
    cout << "void add(...)" << endl;
    return ;
}

int main() {
    add(1, 3);
    add(2.5, 3.6);
    add(3);
    return 0;
}
