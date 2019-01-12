/*************************************************************************
	> File Name: 四平方和.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年01月10日 星期四 14时24分26秒
 ************************************************************************/
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[4] = {0};
    int temp = 0, ans = 0;
	for (int i = 0; i * i < n; i++) {
        int flag = 0;
        for (int j = 0; j * j < n; j++) {
            if (n - i * i - j * j <= 0) continue;
			for (int k = 0; k * k < n; k++) {
                if (n - i * i - j * j - k * k <= 0) continue;
				double temp = sqrt(n - i * i - j * j - k * k);
                if (temp == (int)temp) {
                    flag = 1;
                    cout << i << " " << j << " " << k << " " << temp;
                    break;
                }
            }
            if (flag) break;
        }
        if (flag) break;
    }
	return 0;
}
