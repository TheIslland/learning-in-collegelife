/*************************************************************************
	> File Name: LeetCode_121_买卖股票的最佳时机.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年01月16日 星期三 14时57分13秒
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
int maxProfit(int* prices, int pricesSize) {
        int min = INT_MAX, max = 0;
    for (int i = 0; i < pricesSize; i++) {
                if (prices[i] < min) min = prices[i];
                else if (prices[i] - min > max) max = prices[i] - min;
            
    }
        return max;

}

class Solution {
    public:
    void push(int x) {
        if ()
    }
    int maxProfit(vector<int>& prices) {
        queue<int> q;
        for (int i = 0; i < prices.size(); i++) {
            if (q.empty()) {
                q.push(prices[i]);
                continue;
            }
            while (!q.empty() && q.back() >= prices[i]) {
                q.pop();
            }
            q.push(prices[i]);
        }
        int end = q.back();
        q.pop();
        if (q.empty()) return 0;
        start = q.front();
        return end - start;
    }
}
int main() {
    return 0;
}
