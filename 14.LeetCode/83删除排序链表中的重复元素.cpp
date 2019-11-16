/*************************************************************************
	> File Name: 83删除排序链表中的重复元素.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Sun Nov 10 18:44:48 2019
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *p = head, *q;
        while (p != NULL && p->next != NULL) {
            if(p->val == p->next->val) {
                ListNode *node = p->next; 
                p->next = p->next->next;
                node->next = NULL;
            } else {
                p = p->next;
            }
        }
        return head;
    }
};
int main() {
    return 0;
}
