/*************************************************************************
	> File Name: 李白打酒.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年01月18日 星期五 14时56分41秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
 
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::queue;
using std::stack;
int main() {
	int ans = 0;
	for (int i = 31; i < (1<<14); ++i) {
    	int tot_1 = 0;
    	int tot_0 = 0;
    	int num = 2;
    	for (int j = 0; j < 14; ++j) {
        	if (i&(1 << j)) { // 这里判断二进制 i 从右数第 j + 1 位是否为 1
            	tot_1++;
            	num = num * 2;
        	} else {
            	tot_0++;
            	num = num - 1;
        	}  
    	}
    	if (tot_1 == 5 && tot_0 == 9 && num == 1) {
       		++ans; // 记录合法方案数
    	}
	} 
    cout << ans << endl;
    return 0;
}
