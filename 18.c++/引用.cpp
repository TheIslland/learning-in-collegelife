/*************************************************************************
	> File Name: 引用.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2018年12月28日 星期五 02时44分09秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <string>

void swap(int * a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swap1(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
    return ;
}

int& f() {
    int a = 100;
    int &b = a;
    return b;
}
using namespace std;
int main() {
    int a = 1, b = 2;
    (a > b ? a : b) = 3;
    cout << a << " " << b << endl;
    swap(&a, &b);
    swap(a, b);
    int c = 1;
    c = f();
    cout << c << endl;
    return 0;
}
