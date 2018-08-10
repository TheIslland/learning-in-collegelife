/*************************************************************************
	> File Name: oula30gusuan.c
	> Author: 
	> Mail: 
	> Created Time: 2018年07月22日 星期日 11时08分16秒
 ************************************************************************/

#include<stdio.h>
#include<math.h>
int is_eaual(int x) {
    int temp = x, sum =0;
    while(x) {
        sum += (int)pow( x % 10,5 );
        x /= 10;
    }
    return sum == temp;
}
int main() {
    int i  ,j ;
    int ans = 0;
    for(i = 2;i < 354294; i++) {
        //关于上线估算f(n) = 10^(n)与g(n) = 9^5*(n)的交点
        if(!is_eaual(i)) continue;
            ans += i;
    }
    printf("%d\n",ans);
    return 0;
}
