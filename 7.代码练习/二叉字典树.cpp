/*************************************************************************
	> File Name: 二叉字典树.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年01月22日 星期二 22时07分15秒
 ************************************************************************/
#include <iostream>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

#define SIZE 2
#define BASE '0'
#define OK 1
#define ERROR 0

typedef struct TrieNode {
    int flag, count;
    struct TrieNode **child, *fail;
} TrieNode, *BTrie;

typedef struct Queue{
    TrieNode **data;
    int head, tail, length;
} Queue;

char *get_num(char one_of_char_in_buffer) {
    int nums = one_of_char_in_buffer, ret_len = 0;
    char *ret = (char *)malloc(sizeof(char) * 100);
    while (nums) {
        ret[ret_len++] = nums % 2 + '0';
        nums /= 2;
    }
    ret[ret_len] = '\0';
    return ret;
}

Queue *Queue_init(int length) {
    Queue *q = (Queue *)calloc(sizeof(Queue), 1);
    q->data = (TrieNode **)malloc(sizeof(TrieNode *) * length);
    q->length = length;
    q->head = 0;
    q->tail = -1;
    return q;
}

int Queue_push(Queue *q, TrieNode *element) {
    if(q->tail + 1 > q->length) {
        return ERROR;
    }
    q->tail++;
    q->data[q->tail] = element;
    return OK;
}

TrieNode *Queue_front(Queue *q) {
    return q->data[q->head];
}
void Queue_pop(Queue *q) {
    q->head++;
}

int Queue_empty(Queue *q) {
    return q->head > q->tail;
}

void Queue_clear(Queue *q) {
    if (q == NULL) {
        return ;
    }
    free(q->data);
    free(q);
    return ;
}

BTrie BTrie_get_new_node() {
    BTrie p = (BTrie)calloc(sizeof(TrieNode), 1);
    p->child = (TrieNode **)calloc(sizeof(BTrie), 2);
    return p;
}

int BTrie_insert(BTrie root, char *buffer) {
    BTrie p = root;
    int count = 0;
    for (int i = 0; buffer[i]; i++) {
        char *nums = get_num(buffer[i]);
        for (int j = 0; nums[j]; j++) {
            if (p->child[nums[j] - BASE] == NULL) {
                p->child[nums[j] - BASE] = BTrie_get_new_node();
                count++;
            }
            p = p->child[nums[j] - BASE];
        }
        p->flag = 1;
        free(nums);
    }
    p->count = 1;
    return count;
}

void BTrie_build(BTrie root, int node_number) {
    Queue *q = Queue_init(node_number + 10);
    root->fail = NULL;
    Queue_push(q, root);
    while (!Queue_empty(q)) {
        BTrie now_node = Queue_front(q);
        Queue_pop(q);
        for (int i = 0; i < SIZE; i++) {
            if (now_node->child[i] == NULL) {
                if (now_node != root) {
                    now_node->child[i] = now_node->fail->child[i];
                }
                continue;
            }
            BTrie p = (now_node->fail ? now_node->fail->child[i] : root);
            if (p == NULL) {
                p = root;
            }
            now_node->child[i]->fail = p;
            Queue_push(q, now_node->child[i]);
        }
    }
    free(q);
    return ;
}

void BTrie_match_count(BTrie root, char *str) {
    BTrie p = root, q;
    while (str[0]) {
        char *nums = get_num(str[0]);
        for (int i = 0; nums[i]; i++) {
            p = p->child[nums[i] - BASE];
            q = p;
        }
        while (q) {
            q->count += 1;
            q = q->fail;
        }
        if (p == NULL) {
            p = root;
        }
        free(nums);
        str++;
    }
}

void print(BTrie root, char *str, int *ind) {
    BTrie p = root, q;
    while (str[0]) {
        char *nums = get_num(str[0]);
        for (int i = 0; nums[i]; i++) {
            p = p->child[nums[i] - BASE];
        }
        free(nums);
        str++;
    }
    printf("%d: %d\n", *ind, p->count - 1);
}

int main() {
    int n, cnt, i;
    cnt = 0;
    scanf("%d", &n);
    BTrie root = BTrie_get_new_node();
    char str[1006][22];
    for (i = 0; i < n; i++) {
        scanf("%s", str[i]);
        cnt += BTrie_insert(root, str[i]);
    }
    BTrie_build(root, cnt);
    char buff[1000009] = {0};
    scanf("%s", buff);
    BTrie_match_count(root, buff);
    for (int j = 0; j < i; j++) {
        print(root, str[j], &j);   
    }
    return 0;
}
