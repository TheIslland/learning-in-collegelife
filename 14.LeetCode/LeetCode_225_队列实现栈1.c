/*************************************************************************
	> File Name: LeetCode_225_队列实现栈1.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2018年10月25日 星期四 19时05分20秒
 ************************************************************************/

typedef struct Queue {
    int *data;
    int head, tail, length;
}Queue;

Queue *init(int length) {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->data = (int *)malloc(sizeof(int) * length);
    q->length = length;
    q->head = 0;
    q->tail = -1;
    return q;
}

int push(Queue *q, int element) {
    if(q->tail + 1 >= q->length) {
        return 0;
    }
    q->tail++;
    q->data[q->tail] = element;
    return 1;
}

int front(Queue *q) {
	return q->data[q->head];
}

void pop(Queue *q) {
	q->head++;
}

int empty(Queue *q) {
	return q->head > q->tail;
}

void clear(Queue *q) {
    free(q->data);
    free(q);
}
typedef struct {
    Queue *q;     
} MyStack;

/** Initialize your data structure here. */
MyStack* myStackCreate(int maxSize) {
    Queue *obj = (Queue * )malloc(sizeof(Queue));
    obj->q = init(maxSize);
    return obj;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
    push(obj->q, x);
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
    if (!empty(obj)) {
        int local = q:->tail;
        for (int i = q->head)
    }
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
    
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
    
}

void myStackFree(MyStack* obj) {
    
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * struct MyStack* obj = myStackCreate(maxSize);
 * myStackPush(obj, x);
 * int param_2 = myStackPop(obj);
 * int param_3 = myStackTop(obj);
 * bool param_4 = myStackEmpty(obj);
 * myStackFree(obj);
 */
