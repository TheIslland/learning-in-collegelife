/*************************************************************************
	> File Name: 堆排序.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2018年12月16日 星期日 19时37分01秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Heap.h"

int main() {
    srand(time(0));
    int arr[10] = {0};
    for (int i = 0; i < 10; i++) {
        arr[i] = rand() % 1000;
    }
    heap_sort(arr, 10);
    return 0;
}
