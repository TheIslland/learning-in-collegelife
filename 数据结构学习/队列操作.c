/*************************************************************************
	> File Name: 队列操作.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2018年10月11日 星期四 17时54分24秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ERROR 0
#define OK 1
typedef struct Queue {
    int *data;
    int head, tail, length;
}Queue;

void init(Queue *q, int length) {
    q->data = (int *)malloc(sizeof(int) * length);
    q->length = length;
    q->head = 0;
    q->tail = -1;
}

int push(Queue *q, int element) {
    if (q->tail + 1 > q->length ) {
        return ERROR;
    }
    q->tail++;
    q->data[q->tail] = element;
    return OK;
}

void front(Queue *q) {
    printf("%d\n", q->data[q->head]);
}

void pop(Queue *q) {
    q->head++;
}

int empty(Queue *q) {
    return q->head > q->tail;
}

void output(Queue *q) {
    for (int i = q->head; i <= q->tail; i++) {
        printf("%d ", q->data[i]);
    }
    printf("\n");
} 
int main() {
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    init(queue, 100);
    for (int i = 0; i < 10; i++) {
        push(queue, i);
    }
    front(queue);
    pop(queue);
    output(queue);
    return 0;
}
