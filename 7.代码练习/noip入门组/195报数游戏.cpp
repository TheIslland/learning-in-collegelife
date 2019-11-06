/*************************************************************************
	> File Name: 195报数游戏.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Tue Nov  5 15:37:44 2019
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<iomanip>
#include<cstdio>
#include<cstring>
using namespace std;
#define MAX_N 100005
typedef long long ll;
/*int binary_search(ll a[], ll l, ll r, ll x) {
    ll mid = (l + r) >> 1;
    while (l <= r) {
        mid = (l + r) >> 1;
        if (a[mid] == x) return 1;
        else if (a[mid] > x) r = mid - 1;
        else l = mid + 1;
    }
    return 0;
}*/
int binary_search(ll a[], ll l, ll r, ll x) {
    ll mid = (l + r) >> 1;
    while (l <= r) {
        mid = (l + r) >> 1;
        if (a[mid] == x) return a[mid];
        else if (a[mid] > x) r = mid - 1;
        else l = mid + 1;
    }
    return (a[0] > x ? a[0] : a[r]);
}

int main() { 
    int n, m;
    ll a[MAX_N] = {0};
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    ll temp;
    for (ll i = 0; i < m; i++) {
        scanf("%lld", &temp);
        cout << binary_search(a, 0, n - 1, temp) << (i < m - 1 ? " " : "");
    }
    cout << endl;
    return 0;
}
