/*************************************************************************
	> File Name: 斐波那契.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年01月18日 星期五 20时05分44秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;
class Fib {
private:
    int a0;
    int a1;
public:
    Fib() {
        a0 = 0;
        a1 = 1;
    }
    Fib(int n) {
        a0 = 0;
        a1 = 1;
        for (int i = 2; i <= n; i++) {
            int t = a1;
            a1 = a0 + a1;
            a0 = t;
        }
    }
    int operator()() { //每次执行一次输出一次
        int ret = a1;
        a1 = a1 + a0;
        a0 = ret;
        return ret;
    }
    int operator() (int n) {
        a0 = 0;
        a1 = 1;
        int ret = a1;
        for (int i = 2; i <= n; i++) { //返回第ｎ次的斐波那契值
            ret = a1;
            a1 = a0 + a1;
            a0 = ret;
        }
        return ret;
    }
};
int main() {
    Fib fib;
    for (int i = 0; i < 10; i++) {
        cout << fib() << endl;;
    }
    cout << fib(10) << endl;
    cout << endl;
    Fib fib1(10);
    for (int i = 0; i < 10; i++) {
        cout << fib1() << endl;
    }
    return 0;
}
