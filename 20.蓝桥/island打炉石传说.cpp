/*************************************************************************
	> File Name: island打炉石传说.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年01月18日 星期五 19时13分40秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;
typedef struct Node {
    int cost, d, w;
}Node;
int main() {
    int n, ans = 0;
    cin >> n;
    Node arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i].cost >> arr[i].d >> arr[i].w;
    }
    for (int i = 0; i < (1 << n); i++) {
        int judg = 1;
        int sum_w = 0;
        int cost = 0;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                sum_w += arr[j].w;
                cost += arr[j].cost;
                if (arr[j].d == 0) judg = 0;
            }
        }
        if (judg) continue;
        if (cost <= 10 && sum_w > ans) ans = sum_w;
    }
    cout << ans << endl;
    return 0;
}
