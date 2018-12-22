/*************************************************************************
	> File Name: main.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2018年12月22日 星期六 10时07分15秒
 ************************************************************************/

#include <iostream>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "sort.h"

using namespace std;

int main() {
    srand(time(0));
    int arr[7][MAX_N];
    for (int i = 0; i < 7; i++) {
        rand_num(arr[i], MAX_N);
    }
    Sort s;
    int n;
    out("请选择排序方式:");
    out("1.选择排序");
    out("2.快排");
    out("3.插入排序");
    out("4.冒泡排序");
    out("5.归并排序");
    out("6.希尔排序");
    out("7.堆排序");
    out("8.现有排序全部使用");
    cin >> n;
    switch(n) {
        case 8:
        case 1:
            printf("/------------------------------------------\n");
            __FUNC(arr[0], MAX_N, s.select_sort, num, MAX_N);
            TIME(s.select_sort(arr[0], MAX_N));
            printf("------------------------------------------/\n\n");
            if (n != 8) break;
        case 2:
            printf("/------------------------------------------\n");
            __FUNC(arr[1], MAX_N, s.quick_sort, num, 0, MAX_N - 1);
            TIME(s.quick_sort(arr[1], 0, MAX_N - 1));
            printf("------------------------------------------/\n\n");
            if (n != 8) break;
        case 3:
            printf("/------------------------------------------\n");
            __FUNC(arr[2], MAX_N, s.insert_sort, num, MAX_N);
            TIME(s.insert_sort(arr[2], MAX_N));
            printf("------------------------------------------/\n\n");
            if (n != 8) break;
        case 4:
            printf("/------------------------------------------\n");
            __FUNC(arr[3], MAX_N, s.bubble_sort, num, MAX_N);
            TIME(s.bubble_sort(arr[3], MAX_N));
            printf("------------------------------------------/\n\n");
            if (n != 8) break;
        case 5:
            printf("/------------------------------------------\n");
            __FUNC(arr[4], MAX_N, s.merge_sort, num, 0, MAX_N - 1);
            TIME(s.merge_sort(arr[4], 0, MAX_N - 1));
            printf("------------------------------------------/\n\n");
            if (n != 8) break;
        case 6:
            printf("/------------------------------------------\n");
            __FUNC(arr[5], MAX_N, s.hill_sort, num, MAX_N);
            TIME(s.hill_sort(arr[5], MAX_N));
            printf("------------------------------------------/\n\n");
            if (n != 8) break;
        case 7:
            printf("/------------------------------------------\n");
            __FUNC(arr[6], MAX_N, s.heap_sort, num, MAX_N);
            TIME(s.heap_sort(arr[6], MAX_N));
            printf("------------------------------------------/\n\n");
            if (n != 8) break;
    }
    return 0;
}
