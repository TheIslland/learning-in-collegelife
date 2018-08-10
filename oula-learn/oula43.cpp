/*************************************************************************
	> File Name: oula43.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年07月28日 星期六 17时33分38秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int prime[7] = {2, 3, 5, 7, 11, 13 ,17};
long long int judg(int *a) {
    if(a[0] == 0)
    return 0;
    long long int ans = a[0];
    for (int i = 1; i < 8; i++) {
        int sum = a[i] * 100 + a[i + 1] * 10 + a[i + 2];
        if(sum % prime[i - 1] != 0)
            return 0;
    }
    for(int i = 1; i < 10; i++) ans = ans * 10 + a[i];
    return ans;
}
int main() {
    long long int ans = 0;
    int a[10];
    for(int i = 0; i < 10; i++) {
        a[i] = i;
    }
    do {
        ans += judg(a);
    } while(next_permutation(a, a + 10));
    printf("%lld\n",ans);
    return 0;
}

