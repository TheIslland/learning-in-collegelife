/*************************************************************************
	> File Name: 堆积木.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
> Created Time: 2019年01月19日 星期六 16时43分45秒
 ************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
#include <unistd.h>
using namespace std;

int main() {
    int n,m;
    cin >> n >> m;
	vector<int> arr[n + 10];
    for (int i = 1; i <= n; i++) {
		arr[i].push_back(i);
    }
    int a, b;
    for (int i = 0; i < m; i++) {
		cin >> a >> b;
        if (a == b) continue;
        for (int j = 0; j < arr[b].size(); j++) {
			arr[a].push_back(arr[b][j]);
        }
        vector <int> v;
        {
            v.swap(arr[b]);
        }
    }
    for (int i = 1; i <= n; i++) {
        int len = arr[i].size();
        for (int j = 0; j < len; j++) {
            cout << arr[i][j];
            if (j < len - 1) cout << " ";
        }
        cout << endl;
    }
}

