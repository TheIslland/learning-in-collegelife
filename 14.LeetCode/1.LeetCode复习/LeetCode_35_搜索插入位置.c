/*************************************************************************
	> File Name: LeetCode_35_搜索插入位置.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2018年11月12日 星期一 19时02分49秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int searchInsert(int* nums, int numsSize, int target) {
    int head = 0, tail = numsSize, mid;
    while (head < tail) {
        mid = (head + tail) >> 1;
        if (nums[mid] == target) return mid;
        if (nums[mid] > target) tail = mid;
        else head = mid + 1;
    }
    head = 0, tail = numsSize;
    while (head < tail) {
        mid = (head + tail) >> 1;
        if (nums[mid] < tail) tail = mid;
        else head = mid + 1;
    }
    return tail;
}

int main() {
 
return 0;
}
