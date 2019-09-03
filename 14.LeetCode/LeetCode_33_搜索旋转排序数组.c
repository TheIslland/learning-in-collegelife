/*************************************************************************
	> File Name: LeetCode_33_搜索旋转排序数组.c
	> Author: 
	> Mail: 
	> Created Time: Tue Sep  3 16:10:02 2019
 ************************************************************************/

#include<stdio.h>

int search(int* nums, int numsSize, int target) {
    int l = 0, r = numsSize - 1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (nums[mid] == target) return mid;
        if (nums[l] < nums[r]) {
            if (nums[mid] > target) {
                r = mid - 1;
            }   else {
                l = mid + 1;
            }
        } else {
            if (nums[mid] >= nums[l]) {
                if (nums[mid] > target && target > nums[r]) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            } else {
                if (nums[mid] < target && target < nums[l]) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }
    }
    return -1;
}
