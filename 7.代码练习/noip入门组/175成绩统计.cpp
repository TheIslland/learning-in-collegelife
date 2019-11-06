/*************************************************************************
	> File Name: 175成绩统计.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Mon Nov  4 23:58:49 2019
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
int main() {
    int n, m;
    int a[4] = {0};
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> m;
        if (m >= 90 && m <= 100) {
            a[0]++;
        } else if (m >= 80 && m <= 89) {
            a[1]++;
        } else if (m >= 60 && m <= 79) {
            a[2]++;
        } else {
            a[3]++;
        }
    }
    cout << "You " << a[0] << endl;
    cout << "Liang " << a[1] << endl;
    cout << "Zhong " << a[2] << endl;
    cout << "Cha " << a[3] << endl;
    return 0;
}
