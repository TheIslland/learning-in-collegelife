/*************************************************************************
	> File Name: LeetCode_21_合并两个链表.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2018年11月12日 星期一 18时51分17秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *L, *p1, *p2, *r;
    p1 = l1;
    p2 = l2;
    L = (struct ListNode *)malloc(sizeof(struct ListNode *));
    L->next = NULL;
    r = L;
    while (p1 && p2) {
        if (p1->val > p2->val) {
            r->next = p2;
            r = r->next;
            p2 = p2->next;
        } else {
            r->next = p1;
            r = r->next;
            p1 = p1->next;
        }
    }
    if (p1) {
        r->next = p1;
    } else {
        r->next = p2;
    }
    return L->next;
} 

int main() {
 
    return 0;
}
