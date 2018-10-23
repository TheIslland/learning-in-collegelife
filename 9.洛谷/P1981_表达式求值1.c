/*************************************************************************
	> File Name: P1981_表达式求值1.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2018年10月22日 星期一 20时08分22秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*typedef struct Stack {
    int *data;
    int top, size;
} Stack;

Stack *init(int n) {
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->data = (int *)malloc(sizeof(int) * n);
    s->top = -1;
    s->size = n;
    return n;
}

int push(Stack *s, int value) {
    if (s->top + 1 >= s->size) return 0;
    s->data[s->top++] = value;
    return 1;
}

int empty(Stack *s) {
    return s->top == -1;
}

int top(Stack *s) {
    if (empty(s)) return 0;
    return s->data[s->top];
}

void pop(Stack *s) {
    if (empty(s)) return ;
    s->top--;
    return ;
}

int main() {
    int ans = 0, num = 0;
    char str[220000];
    long long a[22000] = {0};
    scanf("%s[^\n]", &str);
    for (int i = 0; i < strlen(str); i++) {
        switch (str[i]) {
            case '*':
            case '+':
            default : a[num] = a[num] * 10 + (str[i] - '0');
        }
    }
    return 0;
}*/
#define MAX 2200000
#define MOD_NUM 10000

int calc(char *str) {
    int total = 0;
    int len = strlen(str);
    for (int i = 0; i < len; i++) str[i] = (str[i] == '+'? 0 : str[i]);
    for (int i = 0; i < len; i += strlen(str + i) + 1) {
        int num = 0, p = 1;
        for (int j = i; str[j]; j++) {
            switch (str[j]) {
                case '*': p *= num; p %= MOD_NUM; num = 0; break;
                default : num = num * 10 + (str[j] - '0');
            }
        }
        p *= num; p %= MOD_NUM;
        total += p;
        total %= MOD_NUM;
    }
    return total;
}

int main() {
    char str[MAX];
    scanf("%[^\n]s", str);
    printf("%d\n", calc(str));
    return 0;
}
