/*************************************************************************
	> File Name: queue.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2018年10月21日 星期日 18时14分03秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef struct Queue {
    int head, length, tail, cnt;
    int *data;
} Queue;

Queue *init (int n) {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->length = n;
    q->data = (int *)malloc(sizeof(int ) * n);
    q->cnt = 0;
    q->head = 0;
    q->tail = -1;
    return q;
}

int push (Queue *q, int value) {
    if (q->cnt == q->length) return 0;
    q->tail += 1;
    if (q->tail >= q->length) q->tail -= q->length;
    q->cnt += 1;
    q->data[q->tail] = value;
    return 1;
}

int empty (Queue *q) {
    return q->cnt == 0;
}

void pop (Queue *q) {
    if (empty(q)) return;
    q->head += 1;
    if (q->head >= q->length) q->head -= q->length;
    q->cnt -= 1;
    return ;
}

int front (Queue *q) {
    if (empty(q)) return 0;
    return q->data[q->head];
}

void clear (Queue *q) {
    if (q == NULL) return ;
    free(q->data);
    free(q);
    return;
}

void output (Queue *q) {
    printf("Queue = [");
    for (int i = 0; i < q->cnt; i = (i + 1) % q->length) {
        int ind = (q->head + i) % q->length;
        printf(" %d", q->data[ind]);
        i + 1 == q->cnt || printf(",");
    }
    printf("]\n");
    return ;
}

int main() {
    #define MAX_OP 2018
    srand (time (0));
    Queue *q = init(MAX_OP);
    for (int i = 0; i < 20; i++) {
        int op = rand() % 4, value = rand () % 100;
        switch (op) {
            case 0:
            case 1:
            case 2:
                push (q, value);
                printf("push %d to queue\n", value);
                output(q);
                break;
            case 3:
                printf("pop %d to queue\n", front(q));
                pop(q);
                output(q);
                break;
        }
    }
    return 0;
}
