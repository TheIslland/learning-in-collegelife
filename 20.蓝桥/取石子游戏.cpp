/*************************************************************************
	> File Name: 取石子游戏.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年03月27日 星期三 19时32分12秒
 ************************************************************************/

#include <iostream>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    int t, n, a, b;
    cin >> t;
    for (int i = 0; i < n; i++) {
        cin >> n >> a >> b;
        if (n / gcd(a, b) & 1) {
            cout << "huaye" << endl;
        } else {
            cout << "suantou" << endl;
        }
    }
    return 0;
}
