/*************************************************************************
	> File Name: oula29.c
	> Author: 
	> Mail: 
	> Created Time: 2018年07月31日 星期二 10时16分48秒
 ************************************************************************/
#include <stdio.h>
#include <string.h>

struct Tuple {
    int p, a;
};

struct Tuple M[10000][4] = {0};
int M_num = 0;

int prime[105] = {0};

void get_M(int a, int b, struct Tuple *M) {
    int m_len = 0;
    while (a != 1) {
        int p_num = 0, pre = prime[a];
        while (a % pre == 0) {
            a /= pre;
            p_num++;
        }
        M[m_len].p = pre;
        M[m_len].a = p_num * b;
        m_len++;
        if (m_len > 4) printf("error");
    }
    return ;
}

int main() {
    for (int i = 2; i <= 100; i++) {
        if (prime[i]) continue;
        for (int j = i; j <= 100; j += i) {
            if (prime[j]) continue;
            prime[j] = i;
        }
    }
    for (int a = 2; a <= 100; a++) {
        for (int b = 2; b <= 100; b++) {
            struct Tuple temp_M[4] = {0};
            get_M(a, b, temp_M);
            int flag = 1;
            for (int i = 0; i < M_num && flag; i++) {
                flag = memcmp(M[i], temp_M, sizeof(temp_M));
            }
            if (flag) {
                memcpy(M[M_num++], temp_M, sizeof(temp_M));
            }
        }
    }
    printf("%d\n", M_num);
    return 0;
}
