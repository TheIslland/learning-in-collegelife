/*************************************************************************
	> File Name: 二分查找函数.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2018年09月23日 星期日 10时40分50秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int binary_search(int (*arr)(int), int x, int n) {
    int left = 0, right = n - 1, mid = 0;
    while (left <= right) {
        mid = (left + right) >> 1;
        if (arr(mid) == x)   return mid;
        if (arr(mid) > x)   right = mid - 1;
        if (arr(mid) < x)   left = mid + 1;
    }
    return -1;
}
int main() {
    int arr[100];
    char *p1 = (char *)(arr + 1); 
    // 等价于*p = &arr[0];
    p1[0] = 'a';
    p1[1] = 'b';
    p1[2] = 'c';
    p1[3] = 'd';
    char *p2 = (char *)(arr + 2);
    p2[0] = 'A';
    p2[1] = 'B';
    printf("%s %x\n", p1, arr[1]);
    return 0;
}
