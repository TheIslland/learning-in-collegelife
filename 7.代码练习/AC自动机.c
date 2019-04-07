/*************************************************************************
	> File Name: AC自动机.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年01月20日 星期日 09时16分16秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_N 10000
#define BASE 'a'
#define SIZE 26

typedef stuct Node {
    int count;
    struct Node **childs;
    struct Node *fail;
}Node, Trie;

Node *new_node() {
    Node *p = (Node *)malloc(sizeof(Node));
    p->childs = (Node **)malloc(sizeof(Node *));
    for (int i = 0; i < SIZE; i++) {
        p->childs[i] = NULL;
    }
    p->fail = NULL;
}

void clear()
int main() {
 
    return 0;
}
