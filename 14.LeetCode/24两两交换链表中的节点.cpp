/*************************************************************************
	> File Name: 24两两交换链表中的节点.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Sun Nov 10 16:48:23 2019
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<iomanip>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
typedef long long ll;
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
    ListNode* SWAP_Node(ListNode* a, ListNode *b) {
        ListNode *temp = b->next;
        b->next = a;
        a->next = temp;
        return b;
    }
    ListNode* swapPairs(ListNode* head) {
        int count = 0, length = 0;
        ListNode *p = head;
        ListNode *q = new ListNode(0);
        q->next = head;
        while (p) {
            p = p->next;
            length++;
        }   
        p = head;
        head = q;
        for (int i = 0; i < length / 2; i++) {
            p = SWAP_Node(p, p->next);
            q->next = p;
            p = p->next->next;
            q = q->next->next;
        }
        return head->next;
    }
};
int main() {
    return 0;
}
