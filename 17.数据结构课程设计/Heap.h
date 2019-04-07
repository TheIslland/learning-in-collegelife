/*************************************************************************
	> File Name: Heap.h
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2018年12月16日 星期日 19时38分46秒
 ************************************************************************/

#ifndef _HEAP_H
#define _HEAP_H

typedef struct Heap {
    int *data, size;
} Heap;

void init(Heap *h, int length_input) {
    h->data = (int *)malloc(sizeof(int) * length_input);
    h->size = 0;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void push(Heap *h, int value) {
    h->data[h->size] = value;
    int current = h->size;
    int father = (current - 1) / 2;
    while (h->data[current] > h->data[father]) {
        swap(&h->data[current], &h->data[father]);
        current = father;
        father = (current - 1) / 2;
    }
    h->size++;
}

void output(Heap *h) {
    for (int i = 0; i < h->size; i++) {
        printf("%d ",  h->data[i]);
    }
    printf("\n");
}

int top(Heap *h) {
    return h->data[0];
}

void update(Heap *h, int pos, int n) {
    int lchild = 2 * pos + 1, rchild = 2 * pos + 2;
    int max_value = pos;
    if (lchild < n && h->data[lchild] > h->data[max_value]) {
        max_value = lchild;
    }
    if (rchild < n && h->data[rchild] > h->data[max_value]) {
        max_value = rchild;
    }
    if (max_value != pos) {
        swap(&h->data[pos], &h->data[max_value]);
        update(h, max_value, n);
    }
}

void pop(Heap *h) {
    swap(&h->data[0], &h->data[h->size - 1]);
    h->size--;
    update(h, 0, h->size);
}

int empty (Heap *h) {
    return h->size == 0;
}

// 请在下面实现堆排序函数 heap_sort
void heap_sort(int *arr, int n) {
    Heap* heap = (Heap *)malloc(sizeof(Heap));
    init(heap, 1000);
    for (int i = 0; i < n; i++) {
        push(heap, *arr);
        arr++;
    }
    for (int i = heap->size - 1; i >= 1; i--) {
        swap(&heap->data[i], &heap->data[0]);
        update(heap, 0, i);
    }
    output(heap);
}

void clear(Heap *h) {
    free(h->data);
    free(h);
}

#endif
