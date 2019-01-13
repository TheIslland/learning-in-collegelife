/*************************************************************************
	> File Name: 两数之和.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年01月13日 星期日 15时35分36秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>
using std::cin;
using std::cout;
using std::endl;
typedef struct Data {
    int val, pos;
}Data;
typedef struct Hashtable {
    Data *data;
    char *flag;
    int n;
} Hashtable;

Hashtable *init(int n) {
    Hashtable *h = (Hashtable *)malloc(sizeof(Hashtable));
    h->data = (Data *)malloc(sizeof(Data) * n);
    h->flag = (char *)calloc(sizeof(char), n);
    h->n = n;
    return h;
}
void clear(Hashtable *h) {
    if (h == NULL) return ;
    free(h->data);
    free(h);
    return ;
}

int hash_func(Hashtable *h, int val) {
    return val % h->n;
}

void insert(Hashtable *h, int val, int ind) {
    int hash = hash_func(h, val);
    int time = 1;
    while (h->flag[hash]) {
        hash += (time++);
        hash %= h->n;
    }
    h->data[hash].val = val;
    h->data[hash].pos = ind;
    h->flag[hash] = 1;
    return ;
}

int query(Hashtable *h, int val) {
    int hash = hash_func(h, val);
    int time = 1;
    while (h->flag[hash] && h->data[hash].val != val) {
        hash += (time++);
        hash %= h->n;
    }
    if (h->flag[hash] == 0) return -1;
    return h->data[hash].pos;
}


#define MAX_N 500
int arr[MAX_N + 5] = {0};

int main() {
    int n, target;
    scanf("%d", &n);
    Hashtable *h = init(3 * n);
    for (int i = 0; i < n; i++) {
        scanf("%d", arr + i);
    }
    scanf("%d", &target);
    for (int i = 1; i <= n; i++) {
        int pos;
        if ((pos = query(h, target  -arr[i])) == -1) {
            insert(h, arr[i], i);
            continue;
        }
        printf("%d %d\n", pos, i);
    }
    clear(h);
    return 0;
}
