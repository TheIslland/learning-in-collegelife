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
    double time[7];
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
            FUNC_INVOKE(arr[0], MAX_N, s.select_sort, num, MAX_N);
            if (n != 8) break;
        case 2:
            FUNC_INVOKE(arr[1], MAX_N, s.quick_sort, num, 0, MAX_N - 1);
            if (n != 8) break;
        case 3:
            FUNC_INVOKE(arr[2], MAX_N, s.insert_sort, num, MAX_N);
            if (n != 8) break;
        case 4:
            FUNC_INVOKE(arr[3], MAX_N, s.bubble_sort, num, MAX_N);
            if (n != 8) break;
        case 5:
            FUNC_INVOKE(arr[4], MAX_N, s.merge_sort, num, 0, MAX_N - 1);
            if (n != 8) break;
        case 6:
            FUNC_INVOKE(arr[5], MAX_N, s.hill_sort, num, MAX_N);
            if (n != 8) break;
        case 7:
            FUNC_INVOKE(arr[6], MAX_N, s.heap_sort, num, MAX_N);
            if (n != 8) break;
    }
    printf("s.select_sort time =");
    ACQUIRE_TIME(time[0], s.select_sort(arr[0], MAX_N));
    printf("s.quick_sort time =");
    ACQUIRE_TIME(time[1], s.quick_sort(arr[1], 0, MAX_N - 1));
    printf("s.insert_sort time =");
    ACQUIRE_TIME(time[2], s.insert_sort(arr[2], MAX_N));
    printf("s.bubble_sort time =");
    ACQUIRE_TIME(time[3], s.bubble_sort(arr[3], MAX_N));
    printf("s.merge_sort time =");
    ACQUIRE_TIME(time[4], s.merge_sort(arr[4], 0, MAX_N - 1));
    printf("s.hill_sort time =");
    ACQUIRE_TIME(time[5], s.hill_sort(arr[5], MAX_N));
    printf("s.heap_sort time =");
    ACQUIRE_TIME(time[6], s.heap_sort(arr[6], MAX_N));
    s.time_sort(time, 7);
    for (int i = 0; i < 7; i++) {
        printf("%lf\n", time[i]);
    }
    return 0;
}
