/*************************************************************************
	> File Name: 数组中只出现一次的两个数.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Thu Oct 17 18:46:35 2019
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;
class Solution { 
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        int len = data.size();
        int mid = 0;
        for (int i = 0; i < len; i++) {
            mid ^= data[i];
        }
        int ml = 0;
        while (ml < 32 && ((mid & 1) == 0)) {
            ml++;
            mid = mid >> 1;
        }
        *num1 = 0;
        *num2 = 0;
        for (int i = 0; i < len; i++) {
            if (isBit(data[i], ml)) {
                *num1 ^= data[i];
            } else {
                *num2 ^= data[i];
            }
        }
    }
    int isBit(int num, int std) {
        while (std) {
            std --;
            num = num >> 1;
        }
        return (num & 1);
    }
};
int main() {
    
    return 0;
}
