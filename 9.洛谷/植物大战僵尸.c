/*************************************************************************
	> File Name: 植物大战僵尸.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2018年10月31日 星期三 18时10分57秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define swap(a, b) {\
    __typeof(a) __temp = a;\
    a = b; b = __temp;\
}

typedef struct Heap {
    int *data, *sp, *num;
    int cnt, size;
} Heap;

Heap *init(int n) {
    Heap *h = (Heap *)malloc(sizeof(Heap));
    h->data = (int *)malloc(sizeof(int) * (n + 1));
    h->sp = (int *)malloc(sizeof(int) * (n + 1));
    h->num = (int *)malloc(sizeof(int) * (n + 1));
    h->cnt = 0;
    h->size = n;
    return h;
}

void push(Heap *h, int value, int sp, int num) {
    if (h->cnt == h->size) return ;
    h->data[++h->cnt] = value;
    h->sp[h->cnt] = sp;
    h->num[h->cnt] = num;
    int ind = h->cnt;
    while (ind > 1) {
        if (h->data[ind] <= h->data[ind >> 1]) break;
        swap(h->data[ind], h->data[ind >> 1]);
        swap(h->sp[ind], h->sp[ind >> 1]);
        swap(h->num[ind], h->num[ind >> 1]);
        ind >>= 1;
    }
    return ;
}

int empty(Heap *h) {
    return h->cnt == 0;
}

void update(Heap *h) {
    for (int i = 1; i <= h->cnt; i++) {
        h->data[i] += h->sp[i];
    }
    for (int i = h->cnt >> 1; i >= 1; i--) {
        int ind = i;
          while ((ind << 1) <= h->cnt) {
            int temp = ind;
            if (h->data[ind] < h->data[ind << 1]) temp = ind << 1;
            if ((ind << 1 | 1) <= h->cnt && h->data[temp] < h->data[(ind << 1 | 1)]) temp = ind << 1 | 1;
            if (ind == temp) break;
            swap(h->data[temp], h->data[ind]);
            swap(h->sp[ind], h->sp[temp]);
            swap(h->num[ind], h->num[temp]);
            ind = temp;
        }
    }
}

int top(Heap *h) {
    if (empty(h)) return 0;
    return h->num[1];
}

void pop(Heap *h) {
    if (empty(h)) return ;
    h->data[1] = h->data[h->cnt];
    h->sp[1] = h->sp[h->cnt];
    h->num[1] = h->num[h->cnt--];
    int ind = 1;
    while ((ind << 1) <= h->cnt) {
        int temp = ind;
        if (h->data[ind] < h->data[ind << 1]) temp = ind << 1;
        if ((ind << 1 | 1) <= h->cnt && h->data[temp] < h->data[(ind << 1 | 1)]) temp = ind << 1 | 1;
        if (ind == temp) break;
        swap(h->data[temp], h->data[ind]);
        swap(h->sp[ind], h->sp[temp]);
        swap(h->num[ind], h->num[temp]);
        ind = temp;
    }
    return ;
}

void clear (Heap *h) {
    if (empty(h)) return ;
    free(h->data);
    free(h->sp);
    free(h->num);
    free(h);
    return ;
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        int n, f, s;
        scanf("%d", &n);
        Heap *heap = init(n);
        for (int j = 0; j < n; j++) {
            scanf("%d %d", &f, &s);
            push(heap, f, s, j + 1);
        }
        printf("Case #%d:\n", i + 1);
        while (heap->cnt != 0) {
            printf("%d", top(heap));
            pop(heap);
            update(heap);
            if (heap->cnt > 0) printf(" ");
        }
        printf("\n");
        clear(heap);
    }
    return 0;
}
