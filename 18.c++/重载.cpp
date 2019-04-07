/*************************************************************************
	> File Name: 重载.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2018年12月28日 星期五 03时57分16秒
 ************************************************************************/
#include <iostream>
#include <cstdio>
using std::cin;
using std::cout;
using std::endl;
using std::string;

namespace my_lib1{
    int add(int x, int y) {
        return x + y;
    }
    int add() {
        return 100;
    }
    string add(string &s1, string &s2) {
        return s1 + s2;
    }
}

using namespace my_lib1;
int (*p1)(int, int);
int (*p2)();

int main() {
    string s1 = "qwe", s2 = "hasdf";
    p1 = add;
    p2 = add;
    int c = (*p1)(1, 2);
    int d = (*p2)();
    cout << c << " " << d << endl; 
    cout << add() << endl;
    cout << add(1, 2) << endl;
    cout << add(s1, s2) << endl;
    printf("%p %p\n", p1, p2);
    return 0;
}
