/*************************************************************************
	> File Name: 两仪剑法.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年03月27日 星期三 19时00分19秒
 ************************************************************************/

#include <iostream>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}
int main() {
    int t, a, b;
    cin >> t;
    for (int i = 0 ; i < t; i++) {
        cin >> a >> b;
        cout << a * b / gcd(a, b) << endl;
    }

    return 0;
 }
