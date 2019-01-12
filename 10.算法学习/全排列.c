/*************************************************************************
	> File Name: 全排列.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年01月11日 星期五 16时51分44秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

//以下全排列函数的非递归实现
void swap(char *a, char *b) { //交换函数
    char temp = *a;
    *a = *b;
    *b = temp;
}

void reverse(char *a, char *b) { //数组翻转
    while (a < b) {
        swap(a++, b--);
    }
}

int next_permutation(char *first, char *end) {
    if (first == end) return 0; // 如果数组首尾指向同一地方则无需翻转已全排列（单个元素）
    char *p = end; 
    char *q = p;
    while (p != first) {
        p--;
        char *find = end;
        if (*p < *q) { //找到第一个非有序递减的数的位置ｐ
            while (*find <= *p) { //找到第一个比*p大的数
                find--;
            }
            swap(p, find); //将p与find的值交换
            reverse(p + 1, end); //翻转p后到末尾的元素保证字典序输出
            return 1;
        }
        q--;
    }
    return 0;
}

int main() { 
    char a[5] = {0, 1, 2, 3, 4};
    do {
        for (int i = 0; i < 5; i++) {
            printf("%d ", a[i]);
        }
        printf("\n");
    } while (next_permutation(a, a + 4));
    return 0;
}
