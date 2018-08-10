/*************************************************************************
	> File Name: oula9.c
	> Author: 
	> Mail: 
	> Created Time: 2018年07月29日 星期日 10时04分04秒
 ************************************************************************/

#include<stdio.h>
int gcd(int a, int b) {
    if(b > a) {
        return gcd(b, a);
    }
    if(b == 0) {
        return a;
    }
    return gcd(b, a % b);
}
int main() {
    int a, b, c;
    for(int i = 1; i < 32; i++) {
        for(int j = i ;j < 32; j++) { 
            if(gcd(j,i) == 1) {
                a = 2 * i * j;
                b = j * j - i * i;
                c = j * j + i * i;
                if(1000 % (a + b + c) == 0) {
                    int n = 1000 / (a + b+ c);
                    printf("%d %d %d\n",a * n, b * n, c * n);
                    printf("%d", a * b * c * n* n* n);
                } 
            }
        }
    }
    return 0;
}
