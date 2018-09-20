/*************************************************************************
	> File Name: function.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2018年09月20日 星期四 19时47分59秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define P(func) {\
    printf("%s = %d\n", #func, func);\
}
int is_prime(int x); // 函数声名
//如果不定移is_prime则不可以生成可执行文件
//但可以加入 -c 生成对象文件
//但是函数可以在其他文件中定义，编译然后连接编译每个.o文件
int max_int(int n, ...);

int main() {
    for (int i = 2; i <= 100; i++) {
        if (is_prime(i)) printf("%d\n", i);   
    } 
    P(max_int(3, 1, 2, 3));
    P(max_int(4, 1, 2, 3, 9));
    P(max_int(5, 1, 12, 3, 9, 10));
    return 0;
}
