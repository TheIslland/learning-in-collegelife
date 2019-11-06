/*************************************************************************
	> File Name: 207评奖2.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Wed Nov  6 19:55:51 2019
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
struct student {
    string name;
    int grade;
};

bool cmp(struct student &a, struct student &b) {
    return a.grade > b.grade;
}

int main() {
    int n, max = -1, min = 1000;
    string name;
    struct student a[35];
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> name;
        int sum = 0, m;
        for (int i = 0; i < 4; i++) {
            cin >> m;
            m > max && (max = m);
            m < min && (min = m);
            sum += m;
        }
        cout << sum << endl;
        struct student temp = {name, sum};
        a[i] = temp;
    }
    sort(a, a + n, cmp);
    cout << a[0].name << endl;
    cout << max << " " << min << endl;
    return 0;
}
