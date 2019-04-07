/*************************************************************************
	> File Name: 蒜头君的新玩具.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2018年10月31日 星期三 16时29分55秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define swap(a, b) {\
    __typeof(a) __temp = a;\
    a = b; b = __temp;\
}

typedef struct Heap {
    double *data;
    int size, cnt;
} Heap;

Heap *init(int n) {
    Heap *h = (Heap *)malloc(sizeof(Heap));
    h->data = (double *)malloc(sizeof(double) * (n + 1));
    h->size = n;
    h->cnt = 0;
    return h;
}

void push(Heap *h, double value) {
    if (h->cnt == h->size) return ;
    h->data[++(h->cnt)] = value;
    int ind = h->cnt;
    while (ind > 1) {
        if (h->data[ind] <= h->data[ind >> 1]) break;
        swap(h->data[ind], h->data[ind >> 1]);
        ind >>= 1;
    }
    return ;
}

int empty(Heap *h) {
    return h->cnt == 0;    
}

double top(Heap *h) {
    if (empty(h)) return 0;
    return h->data[1];
}

void pop(Heap *h) {
    if (empty(h)) return ;
    h->data[1] = h->data[(h->cnt)--];
    int ind = 1;
    while ((ind << 1) <= h->cnt) {
        int temp = ind ;
        if (h->data[temp] < h->data[temp << 1]) temp = ind << 1;
        if ((ind << 1 | 1) <= h->cnt && h->data[temp] < h->data[(ind << 1 | 1)]) temp = ind << 1 | 1;
        if (temp == ind) break;
        swap(h->data[temp], h->data[ind]);
        ind = temp;
    }
    return ;
}

void output(Heap *h) {
    printf("output :");
    for (int i = 1; i <= h->cnt; i++) {
        printf("%lf ", h->data[i]);
    }
    printf("\n");
}

void clear(Heap *h) {
    if (empty(h)) return ;
    free(h->data);
    free(h);
    return ;
}

int main() {
    int n, temp;
    scanf("%d", &n);
    Heap *heap = init(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &temp);
        push(heap, temp);
    }
    while (heap->cnt != 1) {
        double a = top(heap);
        pop(heap);
        double b = top(heap);
        pop(heap);
        double value = pow(a * b * b, 1.0 / 3);
        push(heap, value);
    }
    printf("%.12lf\n", top(heap));
    pop(heap);

    return 0;
}
