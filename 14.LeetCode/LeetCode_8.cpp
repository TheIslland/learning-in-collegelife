/*************************************************************************
	> File Name: LeetCode_8.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年01月13日 星期日 18时27分37秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <string>
int myAtoi(char* str) {
    int i = 0, ret = 0, flag = 1, pre_ret;
    while (str[i] == ' ') ++i;
    if (str[i] == '-') flag = -1, i++;
    else if (str[i] == '+') flag = 1, i++;
    while (str[i] && str[i] <= '9' && str[i] >= '0') {
        pre_ret = ret;
        ret = ret * 10 + (str[i] - '0');
        if (ret / 10 != pre_ret) {
            return flag == -1 ? INT_MIN : INT_MAX;
        }
        i++;
    }
    return ret * flag;
}
