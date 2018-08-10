/*************************************************************************
	> File Name: oula43gai.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年07月28日 星期六 18时15分44秒
 ************************************************************************/

#include<stdio.h>
using namespace std;
int next_permutation(int *begin, int *end)
{
    int *i=begin, *j, *k;
    if (i==end || ++i==end) return 0;   // 0 or 1 element, no next permutation
    for (i=end-1; i!=begin;) {
        j = i--;    // find last increasing pair (i,j)
        if (!(*i < *j)) continue;
        // find last k which not less than i,
        for (k=end; !(*i < *(--k)););
        iter_swap(i,k);
        // now the range [j,end) is in descending order
        reverse(j,end);
        return 1;
    }
    // current is in descending order
    reverse(begin,end);
    return 0;
}
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

