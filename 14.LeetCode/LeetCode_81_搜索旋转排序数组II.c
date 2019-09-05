/*************************************************************************
	> File Name: LeetCode_81_搜索旋转排序数组II.c
	> Author: 
	> Mail: 
	> Created Time: Thu Sep  5 19:55:04 2019
 ************************************************************************/

#include<stdio.h>

bool search(int* nums, int numsSize, int target){
    int l = 0, r = numsSize - 1, mid;
    while (l <= r) {
        mid = (l + r) >> 1;
        if (nums[mid] == target) return true;
        if (nums[l] < nums[r]) {
            if (nums[mid] > target)  r = mid - 1;
            else l = mid + 1;
        } else if (nums[l] == nums[mid] || nums[r] == nums[mid]) {
            l++;
        } else {
            if (nums[l] <= nums[mid]) {
                if (nums[mid] > target && target > nums[r]) r = mid - 1;
                else l = mid + 1;
            } else {
                if (nums[mid] < target && target < nums[l]) l = mid + 1;
                else r = mid - 1;
            }
        }
    }
    return false;
} 
