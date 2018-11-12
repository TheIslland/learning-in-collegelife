/*************************************************************************
	> File Name: LeetCode_35_搜索查找位置.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2018年11月12日 星期一 20时03分45秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int searchInsert(int* nums, int numsSize, int target) {
    int head = -1, tail = numsSize - 1, mid;
    while (head < tail) {
        mid = (head + tail + 1) >> 1;
        if (nums[mid] < target) head = mid;
        else tail = mid - 1;
    }
    return head + 1;
}
