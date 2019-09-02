/*************************************************************************
	> File Name: 旋转数组的最小数字.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon Sep  2 22:05:54 2019
 ************************************************************************/

#include<iostream>
using namespace std;
class Solution {
    public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        int  l = 0, r = rotateArray.size() - 1; 
        while (l < r) { 
            int mid = (l + r) >> 1;  
            if (rotateArray[l] < rotateArray[r]) return rotateArray[l];  
            else if (rotateArray[mid] > rotateArray[l]) l = mid + 1;  
            else if (rotateArray[mid] < rotateArray[r])r = mid;  
            else ++l;  
        } 
        return rotateArray[l]; 
    }
};
