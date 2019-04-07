/*************************************************************************
	> File Name: 三位数.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年03月22日 星期五 17时02分06秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
 
using namespace std;

int a[6] = {1, 2, 3, 4, 5, 6};
int num = 0;
int jiu, bai;
int b[4];

void dfs(int n) {
    if (n == 3) {
        num++;
        if (num == 90) {
            jiu = b[0] * 100 + b[1] * 10 + b[2];
        }
        if (num == 100) {
            bai = b[0] * 100 + b[1] * 10 + b[2];
            return ; 
        }
        return ;
    }
    if (num > 100) return ;
    for (int i = 0; i < 6; i++) {
        b[n] = a[i];
        dfs(n + 1);
    }
    return ;
}

int main() {
    dfs(0);
    cout << bai - jiu << endl;
    return 0;
}
