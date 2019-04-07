/*************************************************************************
	> File Name: 第一个合理位置.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年03月09日 星期六 19时01分54秒
 ************************************************************************/
#include <algorithm>
#include <iostream>
using namespace std;
int find_first_location(int *num, int len, int target) {
    int l = 0, r = len - 1;
    while (l < r) {
        int mid = (l + r) >> 1;
        if (num[mid] >= target) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return r;
}
int main() {
	int num[100000];
	int n, m;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> num[i];
	}
	cin >> m;
	for (int i = 0; i < m; ++i) {
		int value;
		cin >> value;
		cout << find_first_location(num, n, value) << endl;
	}
	return 0;
}
