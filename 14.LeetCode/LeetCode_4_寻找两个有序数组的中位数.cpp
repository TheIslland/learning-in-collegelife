/*************************************************************************
	> File Name: LeetCode_4_寻找两个有序数组的中位数.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun Sep 22 10:25:35 2019
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size(), len2 = nums2.size(), idx1 = 0, idx2 = 0, idx = 0;
        vector<int> sum_arr(len1 + len2, 0);
        while (idx1 != len1 && idx2 != len2) {
            if (nums1[idx1] >= nums2[idx2]) {
                sum_arr[idx++] = nums2[idx2++];
            } else {
                sum_arr[idx++] = nums1[idx1++];
            }
        }
        while (idx1 != len1) sum_arr[idx++] = nums1[idx1++];
        while (idx2 != len2) sum_arr[idx++] = nums2[idx2++];
        if ((len1 + len2) % 2) {
            return sum_arr[(len1 + len2) / 2];
        } else {
            return (double)(sum_arr[(len1 + len2 - 1) / 2] + sum_arr[(len1 + len2) / 2]) / 2;
        }
    }
};

class Solution {
    public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }
        int arr1l = 0, arr1r = nums1.size();
        int len = nums1.size() + nums2.size();
        int arr1 = 0, arr2 = 0;
        while (arr1 <= nums1.size()) {
            arr1 = (arr1l + arr1r) / 2;
            arr2 = len / 2 - arr1;
            int l1 = arr1 == 0 ? INT_MIN : nums1[arr1 - 1];
            int r1 = arr1 == nums1.size() ? INT_MAX : nums1[arr1];
            int l2 = arr2 == 0 ? INT_MIN : nums2[arr2 - 1];
            int r2 = arr2 == nums2.size() ? INT_MAX : nums2[arr2];
            if (l1 > r2) {
                arr1r = arr1 - 1;
            } else if (l2 > r1) {
                arr1l = arr1 + 1;
            } else {
                if (len % 2 == 0) {
                    l1 = l1 > l2 ? l1 : l2;
                    r1 = r1 < r2 ? r1 : r2;
                    return (double)(l1 + r1) / 2;
                } else {
                    return r1 < r2 ? r1 : r2;
                }
            }
        }
        return -1;
    }
};
