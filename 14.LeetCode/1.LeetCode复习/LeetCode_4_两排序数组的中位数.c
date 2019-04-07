/*************************************************************************
	> File Name: LeetCode_4_两排序数组的中位数.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2018年11月10日 星期六 10时44分41秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//对于两个分别长度为k1和k2的两个数组合成一个k = k1 ＋　k2
//对于k1数组中位数a1 = k1 / 2和k2数组中位数a2 = k2 / 2之和相当于k1 + k2 / 2 = k / 2
//相当于数组的一半元素去掉较小一部分,判断k是否为奇数奇数则中位数为a1和a2中小的一个反之为a1 + a2 / 2
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    n = nums1Size + nums2Size;
    if (nums1[nums1Size / 2] > nums2[nums2Size / 2]) {
        nums1 + (nums1Size / 2 - 1);
        nums2 + nums2Size / 2;
    } else {
        nums1 + nums1Size / 2;
        nums2 + (nums2Size / 2 - 1);
    }
    if (n % 2) {
        return *nums1 < *nums2 ? *nums1 : *nums2;
    } else {
        return (*nums1 + *nums2) / 2.0;
    }
}
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int n = nums1Size + nums2Size;
    int mid1 = nums1Size % 2 ? nums1Size / 2 : (nums1Size - 1) / 2, mid2 = nums2Size % 2 ? nums2Size / 2 : (nums2Size - 1) / 2;
    if (nums1Size == 0) {
        if (n % 2) {
            return nums1[mid1];
        } else {
            return (nums1[mid1] + nums1[mid1 + 1]) / 2.0;
        }
    }
    if (nums2Size == 0) {
        if (n % 2) {
            return nums2[mid2];
        } else {
            return (nums2[mid2] + nums2[mid2 + 1]) / 2.0;
        }
    } 
	printf("%d %d num = %d\n", mid1, mid2, n);
    if (nums1[mid1] > nums2[mid2]) {
        if (n % 2) {
            return nums1[mid1] < nums2[mid2 + 1] ? nums1[mid1] : nums2[mid2 + 1];
        } else {
            return (nums1[mid1] + nums2[mid2 + 1]) / 2.0;
        }
    } else {
        if (n % 2) {
            return nums1[mid1 + 1] < nums2[mid2] ? nums1[mid1 + 1] : nums2[mid2];
        } else {
            return (nums1[mid1 + 1] + nums2[mid2]) / 2.0;
        }
    }
}
