/*************************************************************************
	> File Name: 数组中重复的数字.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Fri Oct 18 18:19:29 2019
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;
class Solution {
public:
    bool duplicate(int numbers[], int length, int* duplication) {
        for(int i=0;i!=length;++i){ 
            int index=numbers[i]%length;  
            if(numbers[index]>=length){  
                *duplication=index;   
                return 1;   
            }  
            numbers[index]+=length;  
        } 
        return 0; 
    }
};
int main() {
    return 0;
}
