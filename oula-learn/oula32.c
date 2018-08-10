/*************************************************************************
	> File Name: oula32.c
	> Author: 
	> Mail: 
	> Created Time: 2018年07月27日 星期五 14时18分40秒
 ************************************************************************/

#include<stdio.h>
int is_valid(int a, int b, int c) {
    int num[10] = {0};
    if(!get_dight(a, num)) return 0;
    if(!get_dight(b, num)) return 0;
    if(!get_dight(c, num)) return 0;
    return 1;
}

int valid[MAX_N] = {0};

int main() {
    int ans = 0;
    for(int a = 2; digit(a) + digit(a) + digit(a * a) <= 9; a++) {
        for(int b = a + 1;digit(a) + digit(b) + digit(a * b) <= 9; b++) {

        }
    }
    return 0;
}
