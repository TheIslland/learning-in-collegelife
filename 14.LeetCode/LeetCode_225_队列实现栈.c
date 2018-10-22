/*************************************************************************
	> File Name: LeetCode_225_队列实现栈.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2018年10月22日 星期一 18时51分45秒
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


typedef struct Mystack{
    Queue *q1;
    Queue *q2;
} MyStack;

/** Initialize your data structure here. */
MyStack* myStackCreate(int maxSize) {
    MyStack *obj = (MyStack *)malloc(sizeof(MyStack));
    obj->q1 = init(maxSize + 10);
    obj->q2 = init(maxSize + 10);
    return obj;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
    push(obj->q1, x);
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
    if (!empty(obj->q1)) {
        int num = 0;
        while(num < obj->q1->tail) {
            num++;
            push(obj->q2, front(obj->q1));
            pop(obj->q1);
        }
    }
   // printf("%d\n", front(obj->q1));
    int temp = front(obj->q1);
    pop(obj->q1);
    obj->q1->head = 0;
    obj->q1->tail = -1;
    while (!empty(obj->q2)) {
        push(obj->q1, front(obj->q2));
        //printf("%d\n", front(obj->q2));
        pop(obj->q2);
    }
    obj->q2->head = 0;
    obj->q2->tail = -1;
    return temp;
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
    if (!empty(obj->q1)) {
        int num = 0;
        while(num < obj->q1->tail) {
            num++;
            push(obj->q2, front(obj->q1));
            //printf("%d ", obj->q1->tail);
            pop(obj->q1);
        }
    }
    int temp = front(obj->q1);
    push(obj->q2, front(obj->q1));
    pop(obj->q1);
    obj->q1->head = 0;
    obj->q1->tail = -1;
    while (!empty(obj->q2)) {
        push(obj->q1, front(obj->q2));
        //printf("%d\n", front(obj->q2));
        pop(obj->q2);
    }
    obj->q2->head = 0;
    obj->q2->tail = -1;
    return temp;
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
    if(empty(obj->q1)) return true;
    else return false;
}

void myStackFree(MyStack* obj) {
    if (empty(obj->q1)) return ;
    clear(obj->q1);
    free(obj);
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
