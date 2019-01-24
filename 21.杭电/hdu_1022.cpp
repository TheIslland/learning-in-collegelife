/*************************************************************************
	> File Name: hdu_1022.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年01月24日 星期四 15时29分19秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <stack>

using namespace std;

int main() {
    int n;
    char str1[15] = {0}, str2[15] = {0};
    while (scanf("%d %s %s", &n, str1, str2) != EOF) {
        stack<int> s1;
        int num1[15] = {0}, num2[15] = {0}, ans[30];
        for (int i = 0; str1[i]; i++) num1[i] = str1[i] - '0';
        for (int i = 0; str2[i]; i++) num2[i] = str2[i] - '0';
        int cnt = 0;
        int flag = 0;
        int ind = 0;
        for (int i = 0; i < n; i++) {
            s1.push(num1[i]);
            ans[ind++] = 1;
            while (!s1.empty() && s1.top() == num2[cnt]) {
                s1.pop();
                ans[ind++] = 0;
                cnt += 1;
            }
        }
        if (cnt != n) {
            cout << "No." << endl << "FINISH" << endl;
            continue;
        }
        cout << "Yes." << endl;
        for (int i = 0; i < ind; i++) {
            if (ans[i]) cout << "in" << endl;
            else cout << "out" << endl;
        }
        cout << "FINISH" << endl;
    }
    return 0;
}
