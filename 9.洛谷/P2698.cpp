/*************************************************************************
	> File Name: P2698.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年01月17日 星期四 14时59分53秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <cstdio>
#include <cmath> 
#include <climits>
using namespace std;
typedef struct Node {
    int x, y;
}Node;

int main() {
    queue<int> q;
    int n, d, a, b;
    cin >> n >> d;
    Node arr[n + 5], low, high;
    low.y = INT_MAX;
    low.x = INT_MIN;
    for (int i = 0 ; i < n; i++) {
        cin >> a >> b;
        arr[i].x = a;
        arr[i].y = b;
        if (arr[i].y > high.y) {
            high = arr[i];
        } else {
            low = arr[i];
        }
    }
    
    return 0;
}
