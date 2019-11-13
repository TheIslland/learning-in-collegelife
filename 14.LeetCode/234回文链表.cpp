/************************************************************
    File Name : 234回文链表.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2019-11-13 星期三 18:49:30
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
    bool isPalindrome(ListNode* head) {
        int len = 0, len1 = 0;
        ListNode *p = head, *q = head, *Vnode = new ListNode(0);
        Vnode->next = NULL;
        while (p) {
            p = p->next;
            len++;
        }
        len1 = len / 2;
        while (len1--) {
            p = q->next;
            q->next = Vnode->next;
            Vnode->next = q;
            q = p;
        }
        p = Vnode->next;
        (len & 1) && (q = q->next); 
        while (p && q) {
            if (p->val != q->val) return false;
            p = p->next;
            q = q->next;   
        }
        return true;
    }
};
int main() {
    
    return 0;
}