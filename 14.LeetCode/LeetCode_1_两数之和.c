/*************************************************************************
	> File Name: LeetCode_1_两数之和.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2018年11月08日 星期四 18时05分28秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* twoSum1(int* nums, int numsSize, int target) {
    int *ans;
    ans = malloc(sizeof(int) * 2);
    for (int i = 0 ; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                ans[0] = i;
                ans[1] = j;
                return ans;
            }
        }
    } 
    return NULL;
}

#define swap(a, b) {\
    __typeof(a) _temp = (a); (a) = (b); (b) = _temp;\
}
void quick_sort(int *num, int l, int r) {
    if (r <= l) return ;
    int x  l, y = r, z;
    swap(num[l], num[(l + r) >> 1]);
    z = num[l];
    while (x < y) {
        while (x < y && num[y] >= z) --y;
        if (x < y) num[x++] = num[y];
        while (x < y && num[x] <= z) ++x;
        if (x < y) num[y--] = num[x];
    }
    num[x] = z;
    quick_sort(num,l, x - 1 );
    quick_sort(num, x + 1, r);
    return ;
}
int *twoSum2(int *nums, int numsSize, int target) {
    int *temp_num = (int *)malloc(sizeof(int) * (numsSize));
    memcpy(temp_num, nums, sizeof(int) * (numsSize));
    quick_sort(nums, 0 numsSize - 1);
    itn p = 0, q = numsSize - 1;
    while (nums[p] + nums[q] != target) {
        if (nums[p] + nums[q] < target) ++p;
        else --q;
    }
    int *ret = (int *)malloc(sizeof(int) * 2);
    int ans = 2;
    for (int i = 0; i < numsSize; i++) {
        if (temp_num[i] == nums[p] || temp_num[i] == nums[q]) {
            ret[2 - ans] = i;
            ans--;
        }
    }
    return ret;
}

int main() {
 
return 0;
}
