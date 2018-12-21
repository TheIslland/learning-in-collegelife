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

/*typedef struct Queue {
    int head, length, tail, cnt;
    int *data;
} Queue;*/

class Queue {
public:
    Queue(int n = 100);
    int push (int value);
    int empty();
    void pop();
    int front();
    void clear();
    void output();
private:
    int head, length, tail, cnt;
    int *data;
};

Queue::Queue (int n) {
    length = n;
    data = (int *)malloc(sizeof(int ) * n);
    cnt = 0;
    head = 0;
    tail = -1;
}

int Queue::push (int value) {
    if (cnt == length) return 0;
    tail += 1;
    if (tail >= length) tail -= length;
    cnt += 1;
    data[tail] = value;
    return 1;
}

int Queue::empty () {
    return cnt == 0;
}

void Queue::pop () {
    if (empty()) return;
    head += 1;
    if (head >= length) head -= length;
    cnt -= 1;
    return ;
}

int Queue::front () {
    if (empty()) return 0;
    return data[head];
}

void Queue::output () {
    printf("Queue = [");
    for (int i = 0; i < cnt; i = (i + 1) % length) {
        int ind = (head + i) % length;
        printf(" %d", data[ind]);
        i + 1 == cnt || printf(",");
    }
    printf("]\n");
    return ;
}

void Queue::clear () {
    if (data == NULL) return ;
    free(data);
    return;
}
#endif
