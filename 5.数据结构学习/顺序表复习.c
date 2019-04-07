/*************************************************************************
	> File Name: 顺序表复习.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2018年09月06日 星期四 08时32分16秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "status.h"
void init(Vector *vector, int size) {
    vector->size = size;
    vector->length = 0;
    vector->data = (int *)malloc(sizeof(int) * size);
}

void expand(Vector *vector) {
    int *old_data = vector->data;
    int vector->size = vector->size * 2;
    int vector->data = (int *)malloc(sizeof(int) * vector->size);
    for (int i = 0; i < vector->length ; i++) {
        vector->data[i] = old_data[i];
    }
    free(old_data);
}
void insert(Vector *vector, int loc , int value) {
    if (loc < 0 || loc > vector->)
}
 
