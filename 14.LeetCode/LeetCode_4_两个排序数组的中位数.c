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

//二分方法，设一个数组有k1个一个数组有k2个合成数组为k = k1 + k2,分别取两个数组的中位数a1 = k1/2, a2 = k2/ 2,比较a1和a2各去掉的那一半后
//如果为基数取最小的，为偶数取两个之和除２
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int n = nums1Size + nums2Size;
    int mid1 = nums1Size % 2 ? nums1Size / 2 : (nums1Size - 1) / 2, mid2 = nums2Size % 2 ? nums2Size / 2 : (nums2Size - 1) / 2;
    printf("%d %d num = %d\n", mid1, mid2, n);
    if (!n) return 0;
    if (nums1Size == 0) {
        if (n % 2) {
            return nums2[mid2];
        } else {
            return (nums2[mid2] + nums2[mid2 + 1]) / 2.0;
        }
    }
    if (nums2Size == 0) {
        if (n % 2) {
            return nums1[mid1];
        } else {
            return (nums1[mid1] + nums1[mid1 + 1]) / 2.0;
        }
    }
    if
}

