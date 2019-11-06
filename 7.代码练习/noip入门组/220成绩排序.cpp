/*************************************************************************
	> File Name: 220成绩排序.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Wed Nov  6 23:19:06 2019
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
    int grade[5];
};

bool cmp1(struct student a, struct student b) {
    if (a.grade[0] == b.grade[0]) return a.name < b.name;
    return a.grade[0] > b.grade[0];
}
bool cmp2(struct student a, struct student b) {
    if (a.grade[1] == b.grade[1]) return a.name < b.name;
    return a.grade[1] > b.grade[1];
}
bool cmp3(struct student a, struct student b) {
    if (a.grade[2] == b.grade[2]) return a.name < b.name;
    return a.grade[2] > b.grade[2];
}
bool cmp4(struct student a, struct student b) {
    if (a.grade[3] == b.grade[3]) return a.name < b.name;
    return a.grade[3] > b.grade[3];
}
bool cmp5(struct student a, struct student b) {
    if (a.grade[4] == b.grade[4]) return a.name < b.name;
    return a.grade[4] > b.grade[4];
}

int main() {
    int n, max = -1, min = 1000;
    string name;
    struct student a[105];
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i].name;
        cin >> a[i].grade[0] >> a[i].grade[1] >> a[i].grade[2] >> a[i].grade[3];
        a[i].grade[4] = a[i].grade[0] + a[i].grade[1] + a[i].grade[2] + a[i].grade[3];
    }
    sort(a, a + n, cmp1);
    for (int i = 0; i < 4; i++) {
        cout << a[i].grade[0]<< (i < 3 ? " " : "");
    }
    sort(a, a + n, cmp2);
    cout << endl;
    for (int i = 0; i < 4; i++) {
        cout << a[i].name << (i < 3 ? " " : "");
    }
    sort(a, a + n, cmp3);
    cout << endl;
    for (int i = 0; i < 4; i++) {
        cout << a[i].name << (i < 3 ? " " : "");
    }
    sort(a, a + n, cmp4);
    cout << endl;
    for (int i = 0; i < 4; i++) {
        cout << a[i].name << (i < 3 ? " " : "");
    }
    sort(a, a + n, cmp5);
    cout << endl;
    for (int i = 0; i < 4; i++) {
        cout << a[i].name << (i < 3 ? " " : "");
    }
    return 0;
}
