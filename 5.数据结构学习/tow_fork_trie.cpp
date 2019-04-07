/*************************************************************************
	> File Name: tow_fork_trie.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年01月20日 星期日 20时26分48秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;

typedef long long ll;
typedef struct Node {
    int flag;
    struct Node *childs[2];
} Node;

Node *new_node() {
    Node *p = (Node *)calloc(sizeof(Node), 0);
    return p;
}

void insert(Node *root, ll num) {
    Node *p = root;
    while (num) {
        int n = num % 2;
        if (p->childs[n] == NULL) {
            p->childs[n] = new_node();
        }
        p = p->childs[n];
        num /= 2;
    }
    p->flag = 1;
}

int find(Node *root, ll num) {
    Node *p = root;
    while (num) {
        int n = num % 2;
        if (p->childs[n] == NULL) return 0;
        p = p->childs[n];
        num /= 2;
    }
    if (p->flag) return 1;
    return 0;
}

int main() {
    unsigned char str[1000];
    for (int i = 0; i < 4; i++) {
        scanf("%s", str);
        printf("%lld\n", (ll)str);
    }
    return 0;
}
