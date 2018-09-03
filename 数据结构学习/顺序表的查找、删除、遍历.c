/*************************************************************************
	> File Name: 顺序表的查找、删除、遍历.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2018年09月03日 星期一 22时05分35秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define ERROR 0
#define OK 1

typedef struct Vector {
	int size, length;
    int *data;
} Vector;

void init(Vector *vector, int size) {
	vector->size = size;
    vector->length = 0;
    vector->data = (int *)malloc(sizeof(int) * size);
}

void expand(Vector *vector) {
	int *old_data = vector->data;
	vector->size = vector->size * 2;
    vector->data = (int *)malloc(sizeof(int) * vector->size);
    for( int i = 0; i < vector->length; i++) {
		vector->data[i] = old_data[i];
    }
	free(old_data);
}

int insert(Vector *vector, int loc, int value) {
	if (loc < 0 || loc > vector->length) {
		printf("failed\n");
        return ERROR;
    }
    if (vector->length >= vector->size) {
		expand(vector);
    }
    for (int i = vector->length; i > loc; --i) {
		vector->data[i] = vector->data[i - 1];
    }
    vector->length++;
    vector->data[loc] = value;
    printf("success\n");
    return OK;
}

int search(Vector *vector, int value) {
	for(int i = 0; i < vector->length; i++) {
		if(vector->data[i] == value) {
			printf("success\n");
            return OK;
        }
    }
    printf("failed\n");
	return ERROR;
}

int delete_node(Vector *vector, int num) {
	if (num < 0 || num >= vector->length) {
		printf("failed\n");
        return ERROR;
    }
    for(int i = num + 1; i < vector->length; ++i) {
		vector->data[i - 1] = vector->data[i]; 
    }
    vector->length = vector->length - 1;
    printf("success\n");
    return OK;
}

void print(Vector *vector) {
	for (int i = 0; i < vector->length; i++) {
		if(i > 0) printf(" ");
        printf("%d", vector->data[i]);
    }
    printf("\n");
}

void clear(Vector *vector) {
	free(vector->data);
    free(vector);
}

int main() {
    Vector *a = (Vector *)malloc(sizeof(Vector));
    init(a, 20);
	int m, t;
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &t);
        int b,c;
        if(t == 1) {
            scanf("%d %d", &b, &c);
			insert(a, b, c);
        } else if(t == 2) {
			scanf("%d", &b);
            delete_node(a,b);
        } else if(t == 3) {
			scanf("%d", &b);
        	search(a, b);
        } else {
			print(a);
        }
    }
    return 0;
}

