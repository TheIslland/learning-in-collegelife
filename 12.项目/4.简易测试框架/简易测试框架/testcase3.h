/*************************************************************************
	> File Name: testcase3.h
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2018年10月07日 星期日 17时48分37秒
 ************************************************************************/

#ifndef _TESTCASE3_H
#define _TESTCASE3_H
#include "test.h"
#include "is_prime.h"

TEST(test, is_prime_func) {
    EXPECT(is_prime(2), 1);
    EXPECT(is_prime(4), 0);
    EXPECT(is_prime(7), 0);
}

#endif
