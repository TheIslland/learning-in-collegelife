/*************************************************************************
	> File Name: 458年龄排序.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Thu Nov  7 09:28:04 2019
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
    string sex;
    int year[2];
};

bool cmp(struct student a, struct student b) {
    if (a.year[0] == b.year[0] && a.year[1] == b.year[1]) {
        return a.name < b.name;
    }
    else if (a.year[0] == b.year[0]) {
        return a.year[1] > b.year[1];
    }
    return a.year[0] > b.year[0];
}

int main() {
    int n;
    string name, sex;
    struct student a[105];
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i].name >> a[i].sex >> a[i].year[0] >> a[i].year[1];
    }
    sort(a, a + n, cmp);
    for (int i = 0; i < n; i++) {
        cout << a[i].name << " " << a[i].sex << " " << a[i].year[0] << " " << a[i].year[1] << endl;
    }
    return 0;
}
