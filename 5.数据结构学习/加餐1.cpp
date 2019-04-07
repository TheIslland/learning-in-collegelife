/*************************************************************************
	> File Name: 加餐1.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年02月20日 星期三 09时21分39秒
 ************************************************************************/

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
 
using namespace std;

int func(int n) {
    if (n == 0) return 0;
    const int i = 123;
    cout << i << endl;
    int *p = const_cast<int *> (&i);
    *p = 456;
    func(n - 1);
    return 0;
}

int main() {
    func(4); 
    return 0;
}
