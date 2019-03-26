/*************************************************************************
	> File Name: 二进制中1的个数.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年03月26日 星期二 20时03分03秒
 ************************************************************************/
class Solution {
public:
     int  NumberOf1(int n) {
         unsigned int x = n;
         x = ((x & 0xAAAAAAAA) >> 1) + (x & 0x55555555);
         x = ((x & 0xcccccccc) >> 2) + (x & 0x33333333);
         x = ((x & 0xF0F0F0F0) >> 4) + (x & 0x0F0F0F0F);
         x = ((x & 0xFF00FF00) >> 8) + (x & 0x00FF00FF);
         x = ((x & 0xFFFF0000) >> 16) + (x & 0x0000FFFF);
         return x;
     }
};
