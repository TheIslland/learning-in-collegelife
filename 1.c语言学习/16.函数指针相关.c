/*************************************************************************
	> File Name: 函数指针相关.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2018年10月04日 星期四 15时37分49秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <inttypes.h>

int add(int a, int b) {
    return a+b;
}

typedef int (*func)(int, int); 
//在ｔｙｐｅｄｅｆ中ｆｕｎｃ是一个类型
//而去掉ｔｙｐｅｄｅｆ后ｆｕｎｃ才是一个变量

int main() {
    func func_a = (func)add;
    printf("%d\n", func_a(4, 5));
    return 0;
}
