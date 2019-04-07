/*************************************************************************
	> File Name: 两树之和1.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年01月13日 星期日 15时53分43秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <string>
using std::cin;
using std::cout;
using std::endl;

#define MAX_N 500

struct Data{
    int val, pos;
};

vector<Data> arr[MAX_N + 5] = {0};

bool cmp(Data &a, Data &b) {
    return a.val < b.val;
}

int main() {
    int n, len, val;
    cin >> n;
    len = n;
    while (n--) cin >> val, arr.push_back(val, len - n);
    sort(arr.begin(), arr.end(), cmp);
    cin >> val;
    while (arr[i] + arr[j] != val) {
        if (arr[i] + arr[j] < val) ++i;
        else --j;
    }
    if (arr[i].pos > arr[j].pos) swap(arr[i].pos, arr[j].pos);
    cout << arr[i].pos << " " << arr[j].pos << endl;
    return 0;
}
