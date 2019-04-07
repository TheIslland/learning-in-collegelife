/*************************************************************************
	> File Name: P1226.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2018年09月19日 星期三 17时06分22秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef long long int ll;
ll quick_pow (ll a, ll b, ll c) {
    ll ans = 1, base = a;
    while (b) { 
        if (b & 1) ans = ans * base % c;
        base *= base;
        b >>= 1;
        base %= c;
    }
    return ans % c; //防止n 0 nt is the first perfect number不取余
}
int main() {
    ll b, p, k;
    scanf("%lld %lld %lld", &b, &p, &k);
    printf("%lld^%lld mod %lld=%lld", b, p, k, quick_pow(b, p, k));
    return 0;
}
