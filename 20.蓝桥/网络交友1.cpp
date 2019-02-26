/*************************************************************************
	> File Name: 网络交友1.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年02月26日 星期二 08时27分34秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

#define MAX_N 5050

int dad[MAX_N];
int size[MAX_N];

int find(int x) {
    if (dad[x] == x) {
        return x;
    }
    return dad[x] = find(dad[x]);
}

int merage(int x, int y) {
    int fa = find(x), fb = find(y);
    if (fa == fb) return 0;
    if (size[fa] > size[fb]) {
        fa ^= fb, fb ^= fa, fa ^= fb;
    }
    dad[fb] = fa;
    size[fa] += size[fb];
    return 1;
}

int main() {
    int n, ind = 1;
    string A, B;
    map<string, int> square;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> A >> B;
        if (!square.count(A)) {
            square[A] = ind;
            size[ind] = 1;
            dad[ind] = ind;
            ind++;
        }
        if (!square.count(B)) {
            square[B] = ind;
            size[ind] = 1;
            dad[ind] = ind;
            ind++;
        }
        merage(square[A], square[B]);
        cout << size[find(square[A])] << endl;
    }

    return 0;
}
