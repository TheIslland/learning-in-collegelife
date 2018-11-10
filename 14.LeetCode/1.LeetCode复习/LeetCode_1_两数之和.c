/*************************************************************************
	> File Name: LeetCode_1_两数之和1.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2018年11月10日 星期六 08时56分20秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node {
    int val, ind;
} Node;

typedef struct HashTable {
    Node *data;
    int *flag;
    int size;
} HashTable;

int Hash(int val) {
    return val & 0xfffffff;
}

HashTable *init(int num) {
    HashTable *h = (HashTable *)malloc(sizeof(HashTable));
    h->data = (Node *)malloc(sizeof(Node) * num * 2);
    h->size = num * 2;
    h->flag = (int *)calloc(sizeof(int), h->size);
    return h;
}


void insert(HashTable *h, int val, int ind) {
    int hash = Hash(val);
    int pos = hash % h->size;
    int times = 1;
    while (h->flag[pos]) {
        pos += (times * times);
        times++;
        pos %= h->size;
    }
    h->data[pos].val = val;
    h->data[pos].ind = ind;
    h->flag[pos] = 1;
    return ;
} 

Node* search(HashTable *h, int val) {
    int hash = Hash(val);
    int pos = hash % h->size;
    int times = 1;
    while (h->data[pos].val && h->data[pos].val != val) {
        pos += (times * times);
        times++;
        pos %= h->size;
    }
    if (h->flag[pos] == 0) return NULL;
    return h->data + pos;
}

int* twoSum(int* nums, int numsSize, int target) {
    int *ret = (int *)malloc(sizeof(int) * 2);
    HashTable *h = init(numsSize);   
    for (int i = 0; i < numsSize; i++) {
        Node *result = search(h, target - nums[i]);
        if (result) {
            ret[0] = i;
            ret[1] = result.ind;
            break ;
        }
        insert(h, nums[i], i);
    }
    return ret;
}

int main() {
 
return 0;
}
