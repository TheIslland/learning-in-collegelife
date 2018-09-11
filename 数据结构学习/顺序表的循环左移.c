/*************************************************************************
	> File Name: 顺序表的循环左移.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2018年09月11日 星期二 14时26分42秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define ERROR 0
typedef struct Vector {
	int size, length;
    int *data;
} Vector;
void init (Vector *vector, int size) {
	vector->size = size;
    vector->length = 0;
    vector->data = (int *)malloc(sizeof(int) * size);
}

void expend (Vector *vector) {
    int *old_data = vector->data;
    vector->size = vector->size * 2;
    vector->data = (int *)malloc(sizeof(int) * vector->size);
    for (int i = 0; i < vector->length; i++) {
        vector->data[i] = old_data[i];
    }
    free(old_data);
}

int insert (Vector *vector, int loc, int value) {
    if (loc < 0 || loc > vector->length) {
        return ERROR;
    }
    if (vector->length >= vector->size) {
		expend(vector);
    }
	for (int i = vector->length; i > loc; i--) {
        vector->data[i] = vector->data[i - 1];
    }
    vector->data[loc] = value;
    vector->length++;
	return OK;
}

int left_move (Vector *vector, int num) {
	if (vector->length <= 1) {
		return 1;
    }
    for (int i = 0; i < num; i++) {
    	int mov_data = vector->data[0];
    	for (int i = 1; i < vector->length; i++) {
            vector->data[i - 1] = vector->data[i];
        }
        vector->data[vector->length - 1] = mov_data;
    }
    return 1;
}

void output (Vector *vector) {
    for (int i = 0; i < vector->length; i++) {
		printf("%d", vector->data[i]);
        if (i < vector->length - 1) {
			printf(" ");
        }
    }
    printf("\n");
}

void clear (Vector *vector) {
    free(vector->data);
    free(vector);
}
int main () {
    int n, k;
    scanf("%d %d", &n, &k);
    Vector *vector = (Vector *)malloc(sizeof(Vector));
    init(vector, n);
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        insert (vector, i, x);
        }
    left_move(vector, k);
    output(vector);
    clear(vector);
}
