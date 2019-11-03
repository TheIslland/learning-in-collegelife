/*************************************************************************
	> File Name: 128n个数的平均值.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Sun Nov  3 11:02:01 2019
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
int main() {
    int n, m;
    long long int sum = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> m;
        sum += m;
    }
    cout << setiosflags(ios::fixed) << setprecision(2) << sum * 1.0 / n << endl;
    return 0;
}
