/*************************************************************************
	> File Name: oula34.c
	> Author: 
	> Mail: 
	> Created Time: 2018年07月22日 星期日 11时34分51秒
 ************************************************************************/

#include<stdio.h>
#include<math.h>
int a[10];
void init() {
    a[0] = 1;
    a[1] = 1;
    for(int i = 2; i <= 9; i++) {
        a[i] = a[i - 1] * i;
    }
}
int is_num(int x) {
   int cmp = x,sum =0;
    while(x) {
        sum += a[x % 10];
        x /= 10;
    }
    return sum == cmp;
}
int main() {
    init();
     int n = 0;
    for(int i = 10; i < 2903040 ; i++) {
       if(is_num(i)) 
        n += i;
    }
    printf("%d\n", n);
    return 0;
}
