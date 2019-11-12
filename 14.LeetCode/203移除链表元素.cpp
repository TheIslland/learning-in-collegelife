/************************************************************
    File Name : 203移除链表元素.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2019-11-12 星期二 21:03:14
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *vhead = new ListNode(0);
        vhead->next = head;
        ListNode *p = head, *q = vhead, *d_node;
        while (p) {
            if (p->val == val) {
                d_node = p;
                q->next = p->next;
                p = p->next;
                delete d_node;
            } else {       
                q = q->next;
                p = p->next;
            }
        }
        return vhead->next;
    }
};

int main() {
    
    return 0;
}