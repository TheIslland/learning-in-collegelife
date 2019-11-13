/*************************************************************************
	> File Name: test.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2018年10月14日 星期日 20时22分48秒
 ************************************************************************/
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;
typedef struct Stack {
    int *data;
    int top, size;
} stack ;

stack *init(int n) {
    stack *s = (stack *)malloc(sizeof(stack));
    s->data = (int *)malloc(sizeof(int) * n);
    s->top = -1;
	s->size = n;
    return s;
}

int push(stack *s, int value) {
	if (s->top == s->size - 1) return 0;
    s->top++;
    s->data[s->top] = value;
    return 1;
}

int empty(stack *s) {
    return s->top == -1;
}

int top(stack *s) {
	if (empty(s)) return 0;
	return s->data[s->top];   
}

void pop(stack *s) {
	if (empty(s)) return ;	
    s->top--;
}

void clear(stack *s) {
    free(s->data);
    free(s);

}
int main() {
    int n, num = 0, i = 2;
    scanf("%d", &n);
    int a[4] = {1, 2, 3, 4};
    do {
	stack *s = (stack *)malloc(sizeof(stack));
    s = init(n);
    push(s, 1);
    while(!empty(s) || num != n) {        
        if (top(s) == a[num]) {
            //printf("%d ", top(s));
			pop(s);
            num++;
        } else {
            if (i > n) break;
            push(s, i);
            i++;
        }
    }
   // printf("%d", num);
    if (num == n) {
		printf("%d %d %d %d YES\n", a[0], a[1], a[2], a[3]);
    } else {
		printf("%d %d %d %d NO\n", a[0], a[1], a[2], a[3]);
    }
    num = 0;
    i = 2;
    clear(s);
    } while (next_permutation(a, a+4));
    return 0;
}
