/************************************************************
    File Name : 206反转链表.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2019-11-12 星期二 21:21:45
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
    ListNode* reverseList(ListNode* head) {
        ListNode *vhead = new ListNode(0), *p = head, *q;
        vhead->next = NULL;
        while (p) {
            q = p->next;
            p->next = vhead->next;
            vhead->next = p;
            p = q;
        }
        return vhead->next;
    }
};
int main() {
    
    return 0;
}