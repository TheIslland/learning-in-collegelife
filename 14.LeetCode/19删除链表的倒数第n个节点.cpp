/*************************************************************************
	> File Name: 19删除链表的倒数第n个节点.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Sun Nov 10 16:11:18 2019
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
	ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count = 0, length = 0;
    	ListNode* p = head;
		while (p) {
			p = p->next;
            length++;
        }
        if (length == n) {
            ListNode *next_node = head->next, *delete_node = head;
            head = next_node;
            delete delete_node;
            return head;   
        }
        p = head;
		while (count < length - n - 1) {
                    p = p->next;
                    count++;
        }
        //cout << count << " " << length << endl;
        ListNode* delete_node = p->next;
        p->next = delete_node->next;
        delete delete_node;
        return head;
        }
};
int main() {

    return 0;
}
