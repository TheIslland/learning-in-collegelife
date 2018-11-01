/*************************************************************************
	> File Name: 蒜头君捡石子.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2018年11月01日 星期四 19时59分20秒
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define swap(a, b) {\
	__typeof(a) __temp = (a);\
    (a) = (b); (b) = __temp;\
}

typedef struct Node {
    int pi, di;
} Node;

typedef struct Heap {
    Node *data;
    int cnt, size;
} Heap;

int cmp(Node p, Node q) {
	if(p.pi < q.pi) return 1;
    if(p.pi == q.pi && p.di < q.di) return 1;
    return 0;
}

Heap *init(int n) {
	Heap *heap = (Heap *)malloc(sizeof(Heap));
    heap->data = (Node *)malloc(sizeof(Node) * n);
    heap->cnt = 0;
    heap->size = n;
    return heap;
}

void push(Heap *h, Node value) {
	if (h->cnt + 1 >= h->size) return ;
    h->data[h->cnt] = value;
    int ind = h->cnt;
    int f = (ind - 1) >> 1;
    while (ind > 0) {
        if(cmp(h->data[f], h->data[ind])) break;
		swap(h->data[ind], h->data[f]);
        ind = f;
        f = (ind - 1) >> 1;
    }
    h->cnt++;
    return ;
}

int empty(Heap *h) {
	return h->cnt == 0;
}

void updata(Heap *h) {
	int ind = 0;
    int l = ind << 1 + 1;
    int r = ind << 1 + 2;
    while (ind < h->size) {
    	int min = ind;
    	if (l < h->size && cmp(h->data[l], h->data[min])) min = l;
    	if (r < h->size && cmp(h->data[r], h->data[min])) min = r;
    	if (min == ind) break;
    	swap(h->data[min], h->data[ind]);
        ind = min;
    }
}

Node top(Heap *h) {
	return h->data[0];
}

void pop(Heap *h) {
	if (empty(h)) return ;
    h->data[0] = h->data[--h->cnt];
    updata(h);
}

void clear(Heap *h) {
	if (empty(h)) return ;
    free(h->data);
    free(h);
}
int main() {
    int n , t;
    scanf("%d", &t);
    for (int i = 0 ; i < t; i++) {
        scanf("%d", &n);
        int num = 1, ans = 0;
        Heap *heap = init(n + 1);
        for (int j = 0; j < n; j++) {
            Node val;
            scanf("%d %d", &val.pi, &val.di);
            push(heap, val);
        }
    	while (heap->cnt) {
            Node temp;
			if (num % 2) {
				temp = top(heap);
                pop(heap);
                temp.pi = temp.pi + temp.di;
                push(heap, temp);
            } else {
                temp = top(heap);
				pop(heap);
            }
			ans = temp.pi;
            num++;
        }
        printf("%d\n", ans);
        clear(heap);
    }
	return 0;
}

