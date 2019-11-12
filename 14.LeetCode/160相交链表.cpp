/************************************************************
    File Name : 160相交链表.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2019-11-12 星期二 18:18:48
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *p = headA, *q = headB, *temp;
        int len_a = 0, len_b = 0;
        while (p) {
            len_a++;
            p = p->next;
        }
        while (q) {
            len_b++;
            q = q->next;
        }
        int len = (len_b == len_a ? 0 : abs(len_a - len_b));
        p = headA, q = headB;
        if (len_a < len_b) swap(p, q);
        while (len--) {
            p = p->next;
        }
        while (p && q) {
            if (p == q) return p;
            p = p->next;
            q = q->next;
        }
        return NULL;
    }
};
int main() {
    
    return 0;
}