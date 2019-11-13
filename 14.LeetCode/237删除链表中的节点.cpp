/************************************************************
    File Name : 237删除链表中的节点.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2019-11-13 星期三 19:10:44
************************************************************/
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>

using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode *p = node, *q = node->next;
        p->val = q->val;
        p->next = q->next;
        delete q;
    }
};
int main() {
    
    return 0;
}