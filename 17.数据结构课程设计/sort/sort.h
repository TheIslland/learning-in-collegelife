/*************************************************************************
	> File Name: sort.h
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2018年12月19日 星期三 17时57分15秒
 ************************************************************************/

#ifndef _SORT_H
#define _SORT_H
#include <cassert>
#include <iostream>
#define MAX_N 20
#define TEST_TIME(funs) ({\
    int begin = clock();\
    double ret = funs;\
    int end = clock();\
    printf("%lfms\n", (end - begin) * 1.0 / CLOCKS_PER_SEC * 1000);\
    ret;\
})

#define TEST(arr, n, func, args...) {\
    int *num = (int *)malloc(sizeof(int) * n);\
    memcpy(num, arr, sizeof(int) * n);\
    output(num, n);\
    printf("%s = ", #func);\
    func(args);\
    output(num, n);\
    free(num);\
}

#define swap(a,b) {\
    __typeof(a) _temp = a; a = b; b = _temp;\
}

void rand_num(int *num, int n) {
    while(n--) num[n] = rand() % 321;
    return ;
}

void output(int *num, int n) {
    printf("ARR = [");
    for (int i = 0; i < n; i++) {
        printf(" %d", num[i]);
        i == n - 1 || printf(",");
    }
    printf("]\n");
    return ;
}

class Sort{
public:
    double bubble_sort(int *num, int n);
    double heap_sort(int *arr, int n);
    double hill_sort(int *num, int n);
    double select_sort(int *num, int n);
    double insert_sort(int *num, int n);
    double merge_sort(int *num, int l, int r); 
    double quick_sort(int *num, int l, int r);
};

double Sort::bubble_sort(int *num, int n) {
    int times = 1;
    for(int i = 1; i < n && times; i++) {
        times = 0;
        for(int j = 0; j < n - i; j++) {
            if(num[j] <= num[j + 1]) continue;
            swap(num[j], num[j + 1]);
            times++;
        }
    }
    return 1.0;
}

double Sort::hill_sort(int *num, int n) {
    int d, i, j, temp;
    for(d = n / 2; d >= 1;d = d / 2){
        for(i = d; i < n;i++){
            temp = num[i];
            for(j = i - d;(j >= 0) && (num[j] > temp);j = j - d) {
                num[j + d] = num[j];
            }
            num[j + d] = temp;
        }
    }
    return -1;
}

double Sort::insert_sort(int *num, int n) {
    for(int i = 1; i < n; i++) {
        for(int j = i; j > 0 && num[j] < num[j - 1]; --j) {
            swap(num[j], num[j - 1]);
        }
    }
    return 1.0;
}

double Sort::merge_sort(int *num, int l, int r) {
    if(r - l <= 1) {
        if(r - l == 1 && num[l] > num[r]) {
            swap(num[l], num[r]);
        }
        return 1.0;
    }
    int mid = (l + r) >> 1;
    merge_sort(num, l, mid);
    merge_sort(num, mid + 1, r);
    int *temp = (int *)malloc(sizeof(int) * (r - l + 1));
    int p1 = l, p2 = mid + 1, k = 0;
    while(p1 <= mid || p2 <= r) {
        if(p2 > r || (p1 <= mid && num[p1] <= num[p2])) {
            temp[k++] = num[p1++];
        } else {
            temp[k++] = num[p2++];
        }
    }
    memcpy(num + l, temp, sizeof(int) * (r - l + 1));
    free(temp);
    return 1.0;
}

double Sort::quick_sort(int *num, int l, int r) {
    while (l < r) {
        int x = l, y = r, z = num[(l + r) >> 1];
        do {
            while(num[x] < z) ++x;
            while(num[y] > z) --y;
            if(x <= y) {
                swap(num[x], num[y]);
                ++x, --y;
            }
        } while (x <= y);
        quick_sort(num, x, r);
        r = y;
    }
    return 1.0;
}

double Sort::select_sort(int *num, int n) {
    for(int i = 0; i < n - 1; i++) {
        int ind = i;
        for(int j = i + 1; j < n; j++) {
            if(num[ind] > num[j]) ind = j;
        }
        swap(num[i], num[ind]);
    }
    return 1.0;
}

double Sort::heap_sort(int *arr, int n) {
    int *p = arr - 1;
    for (int i = 2; i <= n; i++) {
        int ind = i;
        while (ind > 1) {
            if (p[ind] <= p[ind >> 1]) break;
            swap(p[ind], p[ind >> 1])
            ind >>= 1;
        }
    }
    for (int i = n; i > 1; i--) {
        swap(p[1], p[i]);
        int ind = 1;
        while ((ind << 1) <= i - 1) {
            int temp = ind;
            if (p[temp] < p[ind << 1]) temp = ind << 1;
            if ((ind << 1 | 1) <= i - 1 && p[temp] < p[ind << 1 | 1]) temp = ind << 1 | 1;
            if (temp == ind) break;
            swap(p[temp], p[ind]);
            ind = temp;
        }
    }
    return 1.0;
}

#endif
