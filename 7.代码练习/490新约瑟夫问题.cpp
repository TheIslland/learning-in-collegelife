/*************************************************************************
	> File Name: 490新约瑟夫问题.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Fri Oct 25 21:48:23 2019
 ************************************************************************/
#include<iostream>
#include<algorithm>
using namespace std;

int main() {
    int n;
    int a[32800] = {0}, b[32800] = {0};
    a[1] = 1, b[1] = 1;
    cin >> n;
    for(int i = 2; i <= n; i++) {
        a[i] = (a[i - 1] + 1) % i + 1; 
        if(a[i] == i) b[i] = i; 
        else b[i] = b[a[i]]; 
    }
    cout<< b[n] + n << endl;
}
