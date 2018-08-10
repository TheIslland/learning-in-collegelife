/*************************************************************************
	> File Name: oula24-1.c
	> Author: 
	> Mail: 
	> Created Time: 2018年07月29日 星期日 16时51分15秒
 ************************************************************************/

#include <stdio.h>

#define MAX_N 10


int jnum[MAX_N] = {0};
int dnum[MAX_N] = {0};

void init() {
    jnum[0] = dnum[0] = 1;
    for (int i = 1; i < MAX_N; i++) {
        dnum[i] = 1;
        jnum[i] = i * jnum[i - 1];
    }
    return ; 
}

int judge_num(int n, int k) {
    int ind = (k / jnum[n]) + 1, i = -1;
    while (ind > 0) {
        i++;
        ind -= dnum[i];
    }
    dnum[i] = 0;
    return i;
}

int main() {
    init();
    int n, k;
    scanf("%d%d", &n, &k);
    k -= 1;
    for (int i = n - 1; i >= 0; i--) {
        int num = judge_num(i, k);
        printf("%d", num);
        k %= jnum[i];
    }
    printf("\n");
} 
