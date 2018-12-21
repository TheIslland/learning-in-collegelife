/*************************************************************************
	> File Name: queue1.h
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2018年12月21日 星期五 16时15分33秒
 ************************************************************************/

#ifndef _QUEUE1_H
#define _QUEUE1_H
#include <cassert>
#include <iostream>

typedef struct Queue {
    int head, length, tail, cnt;
    int *data;
} Queue;

class Queue_operation {
public:
    Queue *init(int n);
    int push (Queue *q, int value);
    int empty(Queue *q);
    void pop(Queue *q);
    int front(Queue *q);
    void clear(Queue *q);
    void output(Queue *q);
};

Queue* Queue_operation::init (int n) {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->length = n;
    q->data = (int *)malloc(sizeof(int ) * n);
    q->cnt = 0;
    q->head = 0;
    q->tail = -1;
    return q;
}

int Queue_operation::push (Queue *q, int value) {
    if (q->cnt == q->length) return 0;
    q->tail += 1;
    if (q->tail >= q->length) q->tail -= q->length;
    q->cnt += 1;
    q->data[q->tail] = value;
    return 1;
}

int Queue_operation::empty (Queue *q) {
    return q->cnt == 0;
}

void Queue_operation::pop (Queue *q) {
    if (empty(q)) return;
    q->head += 1;
    if (q->head >= q->length) q->head -= q->length;
    q->cnt -= 1;
    return ;
}

int Queue_operation::front (Queue *q) {
    if (empty(q)) return 0;
    return q->data[q->head];
}

void Queue_operation::output (Queue *q) {
    printf("Queue = [");
    for (int i = 0; i < q->cnt; i = (i + 1) % q->length) {
        int ind = (q->head + i) % q->length;
        printf(" %d", q->data[ind]);
        i + 1 == q->cnt || printf(",");
    }
    printf("]\n");
    return ;
}

void Queue_operation::clear (Queue *q) {
    if (q == NULL) return ;
    free(q->data);
    free(q);
    return;
}
#endif
