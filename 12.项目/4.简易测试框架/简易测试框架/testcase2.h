/*************************************************************************
	> File Name: testcase2.h
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2018年10月07日 星期日 13时09分11秒
 ************************************************************************/

#ifndef _TESTCASE2_H
#define _TESTCASE2_H
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "test.h"
#include "half_sqrt.h"
#include "sqrt.h"
 
TEST(test, half_sqrt_func) {
    srand(time(0));
    for (int i = 0; i < 100; i++) {
        double x = 1.0 * (rand() % 1000) / 10 * 10.0; 
        double y = newton_sqrt(x);
        printf("%lf\n", y);
        EXPECT_lf(half_sqrt(x), y);
    }
}

#endif
