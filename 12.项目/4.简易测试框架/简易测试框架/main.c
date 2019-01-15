/*************************************************************************
	> File Name: main.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2018年10月07日 星期日 11时28分43秒
 ************************************************************************/

#include <stdio.h>
#include "newton.h"
#include "half_sqrt.h"
#include "is_prime.h"
#include "test.h"
#ifdef TEST_FUNC
    #include "testcase1.h"
    #include "testcase2.h"
    #include "testcase3.h"
#endif

int main() {   
    is_prime(2);
    printf("hellow world\n");
	return RUN_ALL_TEST();
}
