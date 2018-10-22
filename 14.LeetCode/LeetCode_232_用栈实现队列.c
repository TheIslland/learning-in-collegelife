/*************************************************************************
	> File Name: LeetCode_232_用栈实现队列.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2018年10月22日 星期一 15时15分04秒
 ************************************************************************/
typedef struct Stack {
    int *data;
    int top, size;
} Stack;

Stack *init(int n) {
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->data = (int *)malloc(sizeof(int) * n);
    s->top = -1;
    s->size = n;
    return s;
}

int empty(Stack *s) {
    return s->top == -1;
}

int top(Stack *s) {
    if (empty(s)) return 0;
    return s->data[s->top];
}

int push(Stack *s, int value) {
    if (s->top + 1 >= s->size) return 0;
    s->top ++;
    s->data[s->top] = value;
    return 1;
}

void pop(Stack *s) {
    if (empty(s)) return ;
    s->top -= 1;
}

void clear(Stack *s) {
    if (s == NULL) return ;
    free(s->data);
    free(s);
    return ;
}

typedef struct MyQueue {
    Stack *stack1;
    Stack *stack2;
} MyQueue;

/** Initialize your data structure here. */
MyQueue* myQueueCreate(int maxSize) {
    MyQueue *obj = (MyQueue *)malloc(sizeof(MyQueue));
    obj->stack1 = init(maxSize);
    obj->stack2 = init(maxSize);
    return obj;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x) {
    push(obj->stack1, x);
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) {
    if (empty(obj->stack2)) {
        while (!empty(obj->stack1)) {
            push(obj->stack2, top(obj->stack1));
            pop(obj->stack1);
        }
    }
    int temp = top(obj->stack2);
    pop(obj->stack2);
    return temp;
}

/** Get the front element. */
int myQueuePeek(MyQueue* obj) {
        if (empty(obj->stack2)) {
        while (!empty(obj->stack1)) {
            push(obj->stack2, top(obj->stack1));
            pop(obj->stack1);
        }
    }
    int temp = top(obj->stack2);
    return temp;
}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj) {
    if (empty(obj->stack1) && empty(obj->stack2)) {
        return true;
    } else return false;
}

void myQueueFree(MyQueue* obj) {
    if (empty(obj->stack1) && empty(obj->stack2)) return ;
    clear(obj->stack1);
    clear(obj->stack2);
    free(obj);
    return ;
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * struct MyQueue* obj = myQueueCreate(maxSize);
 * myQueuePush(obj, x);
 * int param_2 = myQueuePop(obj);
 * int param_3 = myQueuePeek(obj);
 * bool param_4 = myQueueEmpty(obj);
 * myQueueFree(obj);
 */
