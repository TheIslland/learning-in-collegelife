/*************************************************************************
	> File Name: LeetCode_203_移除链表元素.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2018年10月20日 星期六 08时44分18秒
 ************************************************************************/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode ret, *p = &ret, *q = head;
    ret.next = head;
    while (!head) return head;
    while (p->next) {
        if (p->next->val == val) {
            q = p->next;
            p->next = q->next;
        } else {
            p = p->next;   
        }
    }
    return ret.next;
}
