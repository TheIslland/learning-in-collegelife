/*************************************************************************
	> File Name: 水仙花数.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年01月14日 星期一 11时03分28秒
 ************************************************************************/
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main() {
    int n, m;
    while (scanf("%d %d", &n, &m) != EOF) {
        int judg = 0;
        for (int i = n; i <= m; i++) {
            int x = i % 10;
            int y = i / 10 % 10;
            int z = i / 100;
            if (i == pow(x, 3) + pow(y, 3) + pow(z, 3)) {
                if (judg) cout << " ";
                cout << i;
                judg = 1;
            }
        }
        if (!judg) cout << "no";
        cout << endl;
    }
    return 0;
}
