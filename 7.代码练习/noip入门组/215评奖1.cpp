/*************************************************************************
	> File Name: 215评奖1.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Wed Nov  6 22:33:46 2019
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
    struct student a[45];
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> name;
        int sum = 0, m;
        for (int i = 0; i < 4; i++) {
            cin >> m;
            sum += m;
        }
        struct student temp = {name, sum};
        a[i] = temp;
    }
    sort(a, a + n, cmp);
    for (int i = 0; i < 3; i++) {
        cout << a[i].name << endl;
    }
    return 0;
}
