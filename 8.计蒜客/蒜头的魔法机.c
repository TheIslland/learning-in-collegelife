/*************************************************************************
	> File Name: 蒜头的魔法机.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2018年10月22日 星期一 19时51分05秒
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

int main() {
	stack *s = (stack *)malloc(sizeof(stack));
    
    int n, num = 0;
    scanf("%d", &n);
    int a[n];
    for (int i = 0 ; i < n; i++) {
		scanf("%d", &a[i]);
    }
    s = init(n);
    push(s, 1);
    for (int i = 1; i <= n + 1; ) {        
        if (top(s) == a[num]) {
            //printf("%d ", top(s));
			pop(s);
            num++;
        } else {
            push(s, i);
            i++;
        }
    }
   // printf("%d", num);
    if (num == n) {
		printf("YES\n");
    } else {
        printf("NO\n");
    }
    
    return 0;
}
