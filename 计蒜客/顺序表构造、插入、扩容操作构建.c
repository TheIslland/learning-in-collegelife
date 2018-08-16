/*************************************************************************
	> File Name: 顺序表构造、插入、扩容操作构建.c
	> Author: TheIslland
	> Mail: 
	> Created Time: 2018年08月16日 星期四 09时25分16秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define ERROR 0
#define OK 1

typedef struct Vector {
	int size, length;
    int *data;
} Vector;

void init(Vector *vector, int num) {
    vector->size = num;
    vector->length = 0;
    vector->data = (int *)malloc(sizeof(int) * num);
}

void expand(Vector *vector) {
    int *old_data = vector->data;
    vector->size = vector->size * 2;
    vector->data = (int *)malloc(sizeof(int) * vector->size);
    for(int i = 0; i < vector->length; i++) {
        vector->data[i] = old_data[i];
    }
    free(old_data);
}

void insert(Vector *vector, int col, int value) {
    int judg = 0;
    if(col < 0 || col > vector->length) {
		printf("failed\n");
        return 0;
    }
    if(vector->length >= vector->size) {
        expand(vector);
        judg = 1;
    }
    for(int i = vector->length; i > col; --i) {
        vector->data[i] = vector->data[i - 1];
    }
    vector->data[col] = value;
    vector->length++;
    if(judg == 1) printf("expand\n");
    printf("success\n");
}


void clear(Vector *vector) {
	free(vector->data);
    free(vector);
}

int main() {
    Vector *a = (Vector *)malloc(sizeof(Vector));
    init(a, 5);
	int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
		int p, q;
        scanf("%d %d", &p, &q);
        insert(a,p,q); 
    }
    clear(a);
    return 0;
}
