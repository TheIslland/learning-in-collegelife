/*************************************************************************
        > File Name: 多机调度问题.cpp
        > Author: TheIslland
        > Mail: voidland@163.com, 861436930@qq.com
        > Created Time: Thu Nov 14 20:10:23 2019
 ************************************************************************/
#include <algorithm>
#include <cstdio>
#include <iostream>

using namespace std;

struct node {
    int time;
    int index;
} a[10];

bool cmp(node a, node b) { return a.time > b.time; }

int Min(int d[], int m) {
    int mini = 0;
    for (int i = 1; i < m; i++) {
        if (d[i] < d[mini]) mini = i;
    }
    return mini;
}

int main() {
    int n, m;
    int sum = 0;
    int d[10];              //机器运行时间。
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i].time;
        a[i].index = i + 1;
    }
    sort(a, a + n, cmp);
    if (n <= m)
        for (int i = 0; i < n; i++) {
            printf("第%d个机器的作业号：%d，所需时间为：%d\n", i + 1,
                   a[i].index, a[i].time);
        }
    else {
        for (int i = 0; i < m; i++) {
            printf("第%d个机器的作业号：%d，所需时间为：%d\n", i + 1,
                   a[i].index, a[i].time);
        }
        for (int i = 0; i < m; i++) d[i] = a[i].time;
        for (int i = m; i < n; i++) {
            int flag = Min(d, m);
            printf("下一次为机器 %d 来处理作业  ,并且此次处理的作业为：%d\n",
                   flag + 1, a[i].index);
            d[flag] += a[i].time;
        }
    }
    sum = d[0];
    for (int i = 0; i < m; i++)
        if (sum < d[i]) sum = d[i];
    cout << "所需要的最短时间为：" << sum << endl;
    return 0;
}