/*************************************************************************
	> File Name: 461成绩统计.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Thu Nov  7 09:07:02 2019
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<iomanip>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
typedef long long ll;
using namespace std;
int main() {
    int n, m, num1 = 0, num2 = 0, sum = 0;
    string x;
    char c;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> c;
        if (c == 'C') {
            cin >> x;
            num1++;
        }
        else {
            cin >> m;
            num2++;
            sum += m;
        }
    }
    cout << num1 << " " << sum / num2 << endl;
    return 0;
}
