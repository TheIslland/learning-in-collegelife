/*************************************************************************
	> File Name: oula17zhen.c
	> Author: 
	> Mail: 
	> Created Time: 2018年07月25日 星期三 08时51分51秒
 ************************************************************************/

#include<stdio.h>
int length20[20] = {
    0, 3, 3, 5, 4, 4, 3, 5, 5, 4, 3,
    6, 6, 8, 8, 7, 7, 9, 8, 8 };
int length10_bit[10] = {
    0, 0, 6, 6, 5, 5, 5, 7, 6, 6};
int exchenge_length(int x) {
    if(x < 20) {
        return length20[x];
    } else if(x < 100) {
        return length10_bit[x / 10] + length20[x % 10];
    } else if(x < 1000) {
        if(exchenge_length(x % 100)) {
            return exchenge_length(x % 100) + 3 + length20[x / 100] + 7;
        } else {
            return  exchenge_length(x % 100) + length20[x / 100] + 7;
        }
    } else {
        return 11;
    }
}
int main() {
    int ans = 0;
    for(int i = 1; i <= 1000; i++) {
        ans +=  exchenge_length(i);
    }
    printf("%d\n",ans);
    return 0;
}
