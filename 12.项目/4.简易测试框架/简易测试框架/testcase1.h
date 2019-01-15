/*************************************************************************
	> File Name: testcase1.h
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2018年10月07日 星期日 13时08分30秒
 ************************************************************************/

#ifndef _TESTCASE1_H
#define _TESTCASE1_H
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "test.h"
#include "newton.h"
#include "sqrt.h"
 
TEST(test, newton_func) {
    srand(time(0));
    for (int i = 0; i < 100; i++) {
        double x = 1.0 * (rand() % 1000) / 1000 * 10.0; 
        double y = newton_sqrt(x);
        printf("%lf\n", y);
        EXPECT_lf(half_sqrt(x), y);
    }
}

#endif
