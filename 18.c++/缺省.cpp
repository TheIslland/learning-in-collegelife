/*************************************************************************
	> File Name: 缺省.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2018年12月28日 星期五 03时24分21秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int add(int a, int b, int c =2) {
    return a + b + c;
}

int add1(int a = 4, int b = 5) ;
//此时至少应传２个参数

void g(int = 0, int = 1, int = 2) {
    cout << "hello" << endl;
}

int main() {
    int a = 6, b = 6;
    /*错误形式
    cout << add() << endl;
    cout << add(1) << endl;
    */
    cout << add(1, 2) << endl;
    g();
    g(1, 2, 3);
    return 0;
}

/*参数不匹配
int add1(int a = 8, int b = 19) {
    return a + b;
}*/
