/*************************************************************************
	> File Name: 特化.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年01月18日 星期五 10时43分38秒
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
using std::stack;：
template <typename T1, typename T2>
class Test {
public:
    void add(T1 a, T2 b) {

    }
};
template <typename T>
class Test<T, T> {
public:
    void add (T a, T b) {

    }
    void print() {
        cout << endl;
    }
}
int main() {
    Test<int, double> t;
    t.add(1, 3.9);
    return 0;
}
