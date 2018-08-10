/*************************************************************************
	> File Name: oula33.c
	> Author: 
	> Mail: 
	> Created Time: 2018年07月27日 星期五 15时10分49秒
 ************************************************************************/

#include<stdio.h>
int gcd(int a, int b) {
    if(b > a) {
        return gcd(b, a);
    }
    if(b == 0) {
        return a; 
    } else 
        return gcd(b, a % b);
}
int main() {
   int x = 1, y = 1;
    for (int i = 10; i < 99; i++) {
        for (int j = i + 1; j < 99; j++) {
            int a = i / 10;
            int b = i % 10;
            int c = j / 10;
            int d = j % 10;
            if(b == c && i * d == j * a && d != 0 ) {
                printf("%d %d\n",i , j);
            x *= a;
            y *= d;
            }
        }
    }
    printf("%d\n",y / gcd(x , y));
    return 0;
}
