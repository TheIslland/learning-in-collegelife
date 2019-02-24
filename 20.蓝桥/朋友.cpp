#include <iostream>

#define MAX_N 5050
using namespace std;

int father[MAX_N], size[MAX_N];

void init() {
    for (int i = 0; i < MAX_N; i++) {
        father[i] = i;
        size[i] = 1;
    }
}

int find(int x) {
    if (father[x] == x) {
        return x;
    }
    return father[x] = find(father[x]);
}

int merage(int a, int b) {
    int fa = find(a), fb = find(b);
    if (fa == fb) return 0;
    if (size[fa] < size[fb]) {
        fa ^= fb; fb ^= fa; fa ^= fb;
    }
    father[fb] = fa;
    size[fa] += size[fb];
    return 1;
}

int main() {
    int n, m, p, a, b;
    init();
    cin >> n >> m >> p;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        merage(a, b);
    }
    for (int i = 0; i < p; i++) {
        int x, y;
        cin >> a >> b;
        x = find(a);
        y = find(b);
        if (x == y) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}
