/*************************************************************************
	> File Name: friend.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年03月28日 星期四 19时20分24秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
 
using namespace std;

class A {
public:
    A() { x = 1; }
private: 
    int x;
    
    friend void func_wang(const A &);
};

void func_wang(const A &obj) {
    cout << obj.x << endl;
}

int main() {
    A a;
    func_wang(a);
    return 0;
}
