/*************************************************************************
	> File Name: 宏定义.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2018年09月23日 星期日 11时38分33秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#ifdef DEBUG //ifdef 条件编译
//#define P printf("%s : %d\n", __func__, __LINE__)
#define P printf("%s : %d\n", __PRETTY_FUNCTION__, __LINE__)
#else
#define P
#endif
void testfunc() {
    P;
}
int main() {
    P;
    testfunc;
return 0;
}
