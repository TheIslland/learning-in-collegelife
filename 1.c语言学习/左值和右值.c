/************************************************************
    File Name : 左值和右值.c
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2019-12-01 星期天 20:43:23
************************************************************/
#include <stdio.h>

int main() {
    int a = 2, b = 3;
    int c = ++a;
    int d = ++(2 + 3);
    printf("%d = %d, c = %d\n", d, c);
    return 0;
}