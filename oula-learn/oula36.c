/*************************************************************************
	> File Name: oula36.c
	> Author: 
	> Mail: 
	> Created Time: 2018年07月22日 星期日 13时16分40秒
 ************************************************************************/

#include<stdio.h>
int zhuanhuan(int x,int n) {
    int cmp = x,sum = 0;
    while(x) {
    sum = sum * n + x % n;
    x /= n;
   // 通用进制转换
    }
   return sum == cmp ;
}
int main() {
  int i , sum  = 0;
    for(i = 1; i < 1000000; i++) {
        int base2,base10;
        base2 = zhuanhuan(i , 2);
        base10 = zhuanhuan(i , 10);
        if(base2 && base10)    
        sum += i;
    }
    printf("%d\n",sum);
    return 0;    
}
