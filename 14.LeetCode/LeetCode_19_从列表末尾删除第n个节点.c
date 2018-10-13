/*************************************************************************
	> File Name: LeetCode_19_从列表末尾删除第n个节点.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2018年10月13日 星期六 10时29分38秒
 ************************************************************************/
/*
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    if (head == NULL) {
        return head;
    } 
    struct ListNode *current_node = head;
    struct ListNode *next_node = head;
    int count = 1, index = 0;
    while (next_node->next != NULL) {
        next_node = next_node->next;
        count++;
    }
    while (current_node->next != NULL && index < count - n - 1) {
        current_node = current_node->next;
        index++;
    }
    if (count == n) {
        struct ListNode *delete_node = current_node;
        head = head->next;
        free(delete_node);
    }
    if (index == count - n - 1 && current_node->next != NULL) {
        struct ListNode *delete_node = current_node->next;
        current_node->next = delete_node->next;
        free(delete_node);
    }
    return head;
}
