/*************************************************************************
	> File Name: 开放地址法.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2018年11月05日 星期一 19时01分31秒
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct HashTable {
    char **elem;
    int size;
} HashTable;

void init(HashTable *h);
int hash(HashTable *h, char value[]);
int search(HashTable *h, char value[], int *pos, int *times);

void init(HashTable *h) {
    h->size = 2000;
    h->elem = (char **)malloc(sizeof(char *) * h->size);
    for (int i = 0; i < h->size; i++) {
        h->elem[i] = NULL;
    }
}

int hash(HashTable *h, char value[]) {
    int code = 0;
    for (size_t i = 0; i < strlen(value); i++) {
        code = (code * 256 + value[i] + 128) % h->size;
    }
    return code;
}

// 请在下面实现查找函数 search
int search(HashTable *h, char value[], int *pos, int *times) {
    *pos = hash(h, value);
    *times = 0;
    while (h->elem[*pos] != NULL && strcmp(h->elem[*pos], value) != 0) {
        (*times)++;
        if (*times < h->size) {
            *pos = (*pos + 1) % h->size;
        } else {
            return 0;
        }
    }
    if (h->elem[*pos] != NULL && strcmp(h->elem[*pos], value) == 0) {
        return 1;
    } else {
        return 0;
    }
}

void clear(HashTable *h) {
    for (int i = 0; i < h->size; ++i) {
        if (h->elem[i] != NULL) {
            free(h->elem[i]);
        }
    }
    free(h->elem);
    free(h);
}

int main() {
    HashTable *hashtable = (HashTable*)malloc(sizeof(HashTable));
    init(hashtable);
    clear(hashtable);
    return 0;
}
