/*************************************************************************
	> File Name: 有序集合的交运算2.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2018年10月12日 星期五 17时11分08秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct Vector {
    int length;
    int *data;
} Vector;

void init(Vector *a) {
    scanf("%d", &a->length);
    a->data = (int *)malloc(sizeof(int) * (a->length + 50));
    for (int i = 0; i < a->length; i++) {
        scanf("%d", &a->data[i]);
    }
    return ;
}

void func(Vector *a, Vector *b, Vector *c) {
    c->length = 0;
    c->data = (int *)malloc(sizeof(int) * (b->length + 50));
    for (int i = 0, j = 0; i < a->length; i++) {
    while (a->data[i] > b->data[j]) {
            if (++j >= b->length) break;
        }
        if (j >= b->length) break;
        if (a->data[i] < b->data[j]) continue;
    c->data[c->length++] = a->data[i];
    }
    return ;
}

int main() {
    Vector *a = (Vector *)malloc(sizeof(Vector));
    Vector *b = (Vector *)malloc(sizeof(Vector));
    Vector *c = (Vector *)malloc(sizeof(Vector));
    init(a);
    init(b);
    if (a->length < b->length) func(a, b, c);
    else func(b, a, c);
    printf("%d\n", c->length);
    if (c->length) {
      for (int i = 0; i < c->length - 1; i++) {
          printf("%d ", c->data[i]);
      }
      printf("%d\n", c->data[c->length - 1]);
    }
    free(a);
    free(b);
    free(c);
    return 0;
}
