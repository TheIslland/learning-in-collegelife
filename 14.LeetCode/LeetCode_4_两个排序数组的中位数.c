/*************************************************************************
	> File Name: LeetCode_4_两个排序数组的中位数.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2018年11月07日 星期三 17时37分00秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int loc = (nums1Size + nums2Size), n1 = 0, n2 = 0;
    int nums3[2 * loc];
    int max = nums1Size > nums2Size ? nums1Size : nums2Size;
    for (int i = 0; n2 < nums2Size || n1 < nums1Size; i++) {
        if (n2 == nums2Size && n1 < nums1Size) {
            nums3[i] = nums1[n1++];
        } else if (n2 < nums2Size && n1 == nums1Size) {
            nums3[i] = nums2[n2++];
        } else {
            if (nums1[n1] > nums2[n2]) {
                nums3[i] = nums2[n2++];
            } else {
                nums3[i] = nums1[n1++];
            }
        }
    }
    if ((loc) % 2) {
        return nums3[loc >> 1];
    } else {
        return (nums3[(loc >> 1) - 1] + nums3[loc >> 1]) / 2.0;
    }
}

