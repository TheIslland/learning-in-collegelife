/*************************************************************************
	> File Name: 交错级数.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年03月22日 星期五 16时57分39秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
 
using namespace std;
int main() {
    double sum = 0;
    for (int i = 1; i <= 100; i++) {
        double temp = 1.0 / i;
        if (i % 2 == 0) {
            sum -= temp;
        } else {
            sum += temp;
        }
    }
    cout << sum << endl;
    return 0;
}
