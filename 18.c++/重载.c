/*************************************************************************
	> File Name: 重载.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2018年12月28日 星期五 03时57分16秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int add() {
    return 0;
}

int add(int a, int b) {
    return a + b;
}

int add(int a, int b, int c) {
    return a + b + c;
}
int main() {
    printf("%d", add());
    printf("%d", add(1, 2));
    printf("%d", add(1, 2, 3));
return 0;
}
