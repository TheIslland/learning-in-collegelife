/*************************************************************************
	> File Name: 激光样式.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon May  6 19:37:12 2019
 ************************************************************************/

#include<iostream>
using namespace std;

int sum = 0;
int num[31] = {0};

void dfs(int x) {
    if (x == 30) {
        sum++;
        return ;
    }
    if (x == 0 || num[x - 1] == 0) {
        num[x] = 1;
        dfs(x + 1);
        num[x] = 0;
    } else {
        dfs(x + 1);
    }
}
int main() {
    dfs(0);
    cout << sum << endl;
    return 0;
}
