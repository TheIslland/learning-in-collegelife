/*************************************************************************
	> File Name: 明码.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年03月22日 星期五 11时10分48秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
 
using namespace std;

string exc(int num) {
    string ans;
    for (int i = 0; i < 8; i++) {
        if (num % 2) ans += '#';
        else ans += ' ';
        num /= 2;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    int i, j;
    int num[100][100];
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 32; j++) {
            cin >> num[i][j];
        }
    }
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 32; j++) {
            string temp = exc(num[i][j]);
            cout << temp;
            if (j % 2) cout << endl;
        }
        cout << endl;
    }
    return 0;
}
