/*************************************************************************
	> File Name: LeetCode_20_有效的括号.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2018年10月22日 星期一 14时24分23秒
 ************************************************************************/
 
/*第一种方法
typedef struct Stack {
    char *data;
    int top, size;
} Stack;

Stack *init(int n) {
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->data = (char *)malloc(sizeof(char) * n);
    s->top = -1;
    s->size = n;
    return s;
}

void push (Stack *s, char value) {
    if (s->top + 1 >= s->size) return ;
    s->top++;
    s->data[s->top] = value;
    return ;
}

int empty (Stack * s) {
    return s->top == -1;
}
 
int top(Stack *s) {
    if (empty(s)) return 0;
    return s->data[s->top];
}

void pop(Stack *s) {
    if (empty(s)) return ;
    s->top--;
    return ;
}
 
bool isValid(char *s) {
    Stack *st = init(strlen(s) + 10);
    for (int i = 0; i < strlen(s); i++) {
        switch (s[i]) {
            case '(': 
            case '{': 
            case '[': push(st, s[i]); break;
            case ')': 
                   if (top(st) != '(') {
                       return false;
                   } else {
                       pop(st); 
                       break;
                   } 
            case ']':
                   if (top(st) != '[') {
                       return false;
                   } else {
                       pop(st); 
                       break;
                   } 
            case '}':
                   if (top(st) != '{') {
                       return false;
                   } else {
                       pop(st); 
                       break;
                   } 
        }
    }
    if (empty(st)) return true;
    else return false;
}*/

bool isValid(char *s) {
    int num1, num2, num3;
    num1 = num2 = num3 = 0;
    for (int i = 0 ; i < strlen(s); i++) {
        switch (s[i]) {
            case '(': num1++; break;
            case ')': 
                    if (num1 <= 0) return false;
                    else num1--; break;
            case '[': num2++; break;
            case ']':
                    if (num2 <= 0) return false;
                    else num2--; break;
            case '{': num3++; break;
            case '}':
                    if (num3 <= 0) return false;
                    else num3--; break;
        }
    }
    if (num1 == 0 && num2 == 0 && num3 == 0) return true;
    else return false;
}
