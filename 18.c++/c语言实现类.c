/*************************************************************************
	> File Name: c语言实现类.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年01月10日 星期四 20时27分51秒
 ************************************************************************/
#include <stdio.h>
#include "head.h"
int main() {
    demo *p = demo_init(1, 2);
    printf("a = %d\n", getI(p));
    printf("b = %d\n", getJ(p));
    printf("add = %d\n", add(p, 5));
    return 0;
}
