/*************************************************************************
	> File Name: oula43.c
	> Author: 
	> Mail: 
	> Created Time: 2018年07月27日 星期五 15时51分15秒
 ************************************************************************/

#include<stdio.h>
#include<inttypes.h>
#define MAX_N 9876543210
int b[7] = {2, 3, 5, 7, 11, 13, 17};
int64_t exc(int64_t x) {
    for(int i = 9; i >= 0; i++) {
       a[0][x % 10]++;
        a[1][i] = x % 10;
        x /= 10;
    }
    for(int i = 0; i < 10; i++) {
        if(a[0][i] == 0)
        return 0;
    }
    int sum = 0;
    for(int i = 1; i < 8; i++) {
        sum = a[1][i] * 100 + a[1][i + 1] * 10 + a[1][i + 2];
        if(sum % b[i - 1] != 0)
        return 0;
    }
    return 1;
}
int main () {
    int a[10];
    for(int i = 0; i < 10; i++) {
        a[i] = i;
    }
    do {

    } while()
    printf(""PRId64"\n",ans);
    return 0;
}

