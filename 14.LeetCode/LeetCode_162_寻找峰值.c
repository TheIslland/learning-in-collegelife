/*************************************************************************
	> File Name: LeetCode_162_寻找峰值.c
	> Author: 
	> Mail: 
	> Created Time: Fri Sep  6 17:09:59 2019
 ************************************************************************/

#include<stdio.h>
int findPeakElement(int* nums, int numsSize) {
    int l = 0, r = numsSize - 1;
    while (l < r) {
        int mid = (l + r) / 2; 
        if (nums[mid] > nums[mid + 1]) { 
            r = mid;  
        } else if(nums[mid] < nums[mid + 1]) { 
            l = mid + 1;  
        } 
    }
    return l == r ? l : -1;
}
