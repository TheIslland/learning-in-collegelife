/*************************************************************************
	> File Name: template.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年01月16日 星期三 16时45分12秒
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
template <typename T1, typename T2, typename T3>
T1 add(T2 a, T3 b) {
    return static_cast<T1>(a + b);
}

int main() {
    int r1 = add<int>(0.5, 0.2);
    int r2 = add<int, float>(0.3, 0.6);
    int r3 = add<int, float, double>(0.5, 0.5);
    return 0;
}
