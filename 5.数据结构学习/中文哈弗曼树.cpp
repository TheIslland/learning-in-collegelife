/*************************************************************************
	> File Name: 哈弗曼.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2018年10月29日 星期一 18时17分00秒
 ************************************************************************/
#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#define BASE_CNT 26
#define BASE '0'

using namespace std;

typedef long long ll;

typedef struct charactor { 
    char key[3]; 
    ll count; 
    struct charactor *next; 
} Charactor; 

Charactor *add(char *c, Charactor *head, int *length) { 
    int flag = 1; 
    Charactor *p = head; 
    while(p != NULL && flag == 1) { 
        if (strcmp(p->key, c) == 0) 
            flag = 0; 
        else 
            p = p->next; 
    } 
    if(flag == 0) {
        *length += 1;
        p->count++; 
    }
    else { 
        p = head; 
        head = (Charactor *)malloc(sizeof(Charactor)); 
        strcpy(head->key,c); 
        head->count = 1; 
        head->next = p; 
    } 
    return head; 
} 

typedef struct TrieNode {
    int flag;
    struct TrieNode **next;
} TrieNode;

TrieNode *getNewTrieNode() {
    TrieNode *p = (TrieNode *)malloc(sizeof(TrieNode));
    p->next = (TrieNode **)malloc(sizeof(TrieNode *) * 2);
    for (int i = 0; i < 2; i++) {
        p->next[i] = NULL;
    }
    p->flag = 0;
    return p;
}

int TrieNode_insert(TrieNode *node, const char *str) {
    TrieNode *p = node;
    int len = strlen(str);
    for (int i = 0; str[i]; i += 3) {
        for (int j = 0; j < 3; j++) {
            int num = str[i + j];
            while (num) {
                int x = num & 1;
                if (p->next[x] == NULL) {
                    p->next[x] = getNewTrieNode();
                }
                p = p->next[x];
                num /= 2;
            }
        }
        p->flag += 1;
    }
}

int TrieNode_search(TrieNode *node, const char *str) {
    TrieNode *p = node;
    int len = strlen(str);
    for (int i = 0; str[i]; i += 3) {
        for (int j = 0; j < 3; j++) {
            int num = str[i + j];
            while (num) {
                int x = num & 1;
                if (p->next[x] == NULL) {
                    return 0;
                }
                p = p->next[x];
                num /= 2;
            }
        }
    }
    return p->flag;
}

typedef struct Node {
    ll freq;
    char *name;
    int ind;
    struct Node *lchild, *rchild;
    bool operator < (const Node& t)const{
        return freq > t.freq;
    } 
} Node;

typedef struct ans{
    char *str;
    char *code;
}Ans;

void clear(Node *root) {
    if(!root) return ;
    clear(root->lchild);
    clear(root->rchild);
    free(root->name);
    free(root);
    return ;
}

Node *getNewNode(const char *name, ll freq, int ind) {
    Node *p = (Node *)malloc(sizeof(Node));
    //p->name = (char *)malloc(sizeof(char) * 4);
    p->name = strdup(name);
    p->ind = ind;
    p->freq = freq;
    p->lchild = p->rchild = NULL;
    return p;
}

Node *init(Node node) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->name = strdup(node.name);
    p->freq = node.freq;
    p->ind = node.ind;
    p->lchild = node.lchild;
    p->rchild = node.rchild;
    return p;
}

Node *build_node(priority_queue<Node> &q) {
    Node *ret;
    while (q.size() > 1) {
        Node *node1, *node2, *new_node;
        node1 = init(q.top());
        q.pop();
        node2 = init(q.top());
        q.pop();
        ll num = node1->freq + node2->freq;
        new_node = getNewNode("", num, -1);
        new_node->lchild = node2;
        new_node->rchild = node1;
        q.push(*new_node);
   }
    ret = init(q.top());
    q.pop();
    return ret;
}

typedef struct Note {
    char *name;
    char *buff;
}Note;

void extract_node(Node *root, Note *code, int k, char *buff) {
    buff[k] = 0;
    if (root->ind >= 0) {
        code[root->ind].buff = strdup(buff);
        code[root->ind].name = strdup(root->name);
        return ;
    }
    buff[k] = '0';
    extract_node(root->lchild, code, k + 1, buff);
    buff[k] = '1';
    extract_node(root->rchild, code, k + 1, buff);
    return ;
}

void output(Node *root) {
    if (root == NULL) return ;
    output(root->lchild);
    output(root->rchild);
    if (root->ind != -1)
    cout << "node :" << root->name << " " << root->freq << " ind = " << root->ind << endl;
    return;
}


int main() {
    TrieNode *Trie = getNewTrieNode();
    char str[1000][30];
    Charactor *head = NULL; 
	int n, length = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", str[i]);
        for (int j = 0; j < strlen(str[i]); j += 3) {
            char *temp = (char *)malloc(sizeof(char) * 3);
            strncpy(temp, str[i] + j, 3);
            head = add(temp, head, &length);    
        }
    }
    Node *root;
    priority_queue<Node> q;
    for (int i = 0 ; head != NULL ; i++) {
        ll freq;
        Node *temp;
        temp = getNewNode(head->key, head->count, i);
        cout << temp->name << " " << temp->freq << endl;
        q.push(*temp);
        head = head->next;
    }
    root = build_node(q);
    output(root);
    Note code[length];
    char buff[40];
    extract_node(root, code, 0, buff);
    for (int i = 0; i <= n; i++) {
        cout << code[i].name << ": " << code[i].buff << endl;
    }
    return 0;
}
