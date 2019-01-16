/*************************************************************************
	> File Name: LeetCode_53_最大子序和.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年01月16日 星期三 14时40分33秒
 ************************************************************************/
int maxSubArray(int* nums, int numsSize) {
    int res = nums[0], sum = nums[0];
    for (int i = 1; i < numsSize; i++) {
        if (sum > 0) {
            sum += nums[i];
        } else {
            sum = nums[i];
        }
        res = (sum > res ? sum : res);
    }
    return res;
}
