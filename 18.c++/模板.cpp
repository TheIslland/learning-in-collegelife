/*************************************************************************
	> File Name: 模板.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年01月16日 星期三 15时58分39秒
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
#define SWAP(t, a, b) {\
    t (temp) = (a);\
    (a) = (b);\
    (b) = (temp);\
}

void my_swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void my_swap(double &a, double &b) {
    double temp = a;
    a = b;
    b = temp;
}
template <typename T>
void my_swap1(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}
template <typename T>
void my_sort(T *a, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; ++j) {
            if (a[i] > a[j]) {
                my_swap1(a[i], a[j]);
            }
        }
    }
}
int main() {
    string s1 = "wrf", s2 = "cxh";
    int a = 10, b = 20;
    double c = 3.2, d = 4.5;
    SWAP(int, a, b);
    SWAP(double, c, d);
    SWAP(string, s1, s2);
    my_swap(a, b);
    my_swap(c, d);
    cout << a << " " << b << endl;
    cout << c << " " << d << endl;
    cout << s1 << " " << s2 << endl;
    int arr[5] {3, 2, 1, 5, 6};
    my_sort(arr, 5);
    for (auto x: arr) {
        cout << x << " ";
    }
    return 0;
}
