/*************************************************************************
	> File Name: 植物大战僵尸.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2018年11月02日 星期五 17时08分10秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define swap(a, b) {\
    __typeof(a) __temp = (a);\
    (a) = (b); (b) = __temp;\
}

typedef struct Node {
    int fi, ind;
} Node;

typedef struct Heap {
    Node *data;
    int cnt, size;
} Heap;

void init(Heap *h, int n) {
    h->data = (Node *)malloc(sizeof(Node) * n);
    h->cnt = 0;
    h->size = n;
}

int cmp(Node p, Node q) {
    if (p.fi > q.fi) return 1;
    if (p.fi == q.fi && p.ind < q.ind) return 1;
    return 0;
}

void push(Heap *h, Node node) {
    if (h->cnt >= h->size) return ;
    h->data[h->cnt] = node;
    int ind = h->cnt;
    int f = (ind - 1) / 2;
    while (cmp(h->data[ind], h->data[f])) {
        swap(h->data[ind], h->data[f]);
        ind = f;
        f = (ind - 1) / 2;
    }
    h->cnt++;
    return ;
}

int empty(Heap *h) {
    return h->cnt == 0;
}

Node top(Heap *h) {
    return h->data[0];
}

void updata(Heap *h) {
    int ind = 0;
    while ((ind * 2 + 1) < h->cnt) {
        int min = ind;
        int l = ind * 2 + 1;
        int r = ind * 2 + 2;
        if(l < h->cnt && cmp(h->data[l], h->data[min])) min = l;
        if (r < h->cnt && cmp(h->data[r], h->data[min])) min = r;
        if (min == ind) break;
        swap(h->data[min], h->data[ind]);
        ind = min;
    }
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
    return ;
}

int main() {
    int t;
    scanf("%d", &t);
        Heap *s[101];
        for (int j = 1; j < 101; j++) {
            s[j] = (Heap *)malloc(sizeof(Heap));
            init(s[j], 50005);
        }

    for (int i = 0; i < t; i++) {
        int n;
        scanf("%d", &n);
        Node zombine;
        int sp;
        for (int j = 0;j < n; j++) {
            scanf("%d %d", &zombine.fi, &sp);
            zombine.ind = j + 1;
            push(s[sp], zombine);
        }
        for (int j = 0;j < n; j++) {
            int num = 1;
            Node zombine1, zombine2;
            for (int k = 1; k < 101; k++) {
                if (empty(s[k])) continue;
                zombine1 = top(s[num]);
                zombine2 = top(s[k]);
                zombine1.fi = zombine1.fi + j * num;
                zombine2.fi = zombine2.fi + j * k;
                if(cmp(zombine2, zombine1)) {
                    num = k;
                }
            }
            printf("%d", top(s[num]).ind);
            pop(s[num]);
            if (j != n - 1) printf(" ");
        }
        printf("\n");
    }
    for (int i = 1; i < 101; i++) {
        clear(s[i]);
    }
    return 0;
}
