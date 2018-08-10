/*
	> File Name: oula5.c
	> Author: 
	> Mail: 
	> Created Time: 2018年07月22日 星期日 09时39分21秒
 ************************************************************************/

#include<stdio.h>
int gcd(int a,int b) {
    if(b > a) {
        return gcd(b,a);
    } else {
        if(b == 0)
        return a;
        else 
        return gcd(b,a % b);
    }
/*if(!b) return a;
    * return gcd(b, a% b)*/
}
int main() {
    int ans =1;
    for(int i = 1; i<= 20; i++) {
        if(ans % i == 0) continue;
        ans = ans * i / gcd(ans, i);
    }
    printf("%d\n",ans);
    return 0;
}
