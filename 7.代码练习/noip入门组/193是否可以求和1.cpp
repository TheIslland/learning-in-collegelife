
#include<iostream>
#include<algorithm>
#include<iomanip>
#include<cstdio>
using namespace std;
#define MAX_N 100005
typedef long long ll;
void binary_search(ll a[], ll l, ll r, ll x) {
    ll mid = (l + r) >> 1;
    while (l <= r) {
        mid = (l + r) >> 1;
        if (a[mid] == x) {
            printf("Yes");
            return;
        }
        else if (a[mid] > x) r = mid - 1;
        else l = mid + 1;
    }
    printf("No");
    return;
}
int main() {
    ll n, k, s;
    ll a[MAX_N] = {0};
    scanf("%lld", &n);
    for (ll i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    scanf("%lld %lld", &k, &s);
    binary_search(a, 0, n - 1, s - k);
    return 0;
} 