/*************************************************************************
	> File Name: P1981_表达式求值.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2018年10月21日 星期日 16时23分41秒
 ************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define INF 0x3f3f3f3f

int calc(const char *str, int l, int r) {
    int pos = -1, temp_prior = 0, prior = INF - 1;
    for (int i = l; i <= r; i++) {
        int cur_prior = INF;
        switch (str[i]) {
            case '(': temp_prior += 100; break;
            case ')': temp_prior -= 100; break;
            case '+': cur_prior = temp_prior + 1; break;
            case '-': cur_prior = temp_prior + 1; break;
            case '*': cur_prior = temp_prior + 2; break;
            case '/': cur_prior = temp_prior + 2; break;
        }
        if (cur_prior <= prior) {
            prior = cur_prior;
            pos = i;
        }
    }
    if (pos == -1 ) {
        int num = 0;
        for (int i = l; i <= r; i++) {
            if (str[i] < '0' || str[i] > '9') continue;
            num = num * 10 + str[i] - '0';
        }
        return num;
    } else {
        int a = calc(str, l, pos - 1);
        int b = calc(str, pos + 1, r);
        switch (str[pos]) {
            case '+': return a + b; break;
            case '-': return a - b; break;
            case '*': return a * b; break;
            case '/': return a / b; break;
        }
    }
    return 0;
}

#define MAX_N 2100000
#define MOD_NUM 10000
char str[MAX_N];

int calc1 (char *str) {
    int len = strlen(str);
    for (int i = 0; str[i]; i++) str[i] = (str[i] == '+' ? 0 : str[i]);
    int total = 0;
    for (int j = 0; j < len; j+= strlen(str + j) + 1) {
        int num = 0, p = 1;
        for (int i = j; str[i]; i++) {
            switch (str[i]) {
                case '*': p *= num; p %= MOD_NUM; num = 0; break;
                default : num = num * 10 + str[i] - '0';
            }
        }
        p *= num; p %= MOD_NUM;
        total += p;
        total %= MOD_NUM;
    }
    return total;
}
int main() {
    char str[100];
    scanf("%[^\n]s", str);
    int ans;
    ans = calc1(str);
    printf("%d\n", ans);
    return 0;
}
