# LeetCode学习笔记

## LeetCode 19.Remove Nth Node From End of List(删除链表的倒数第N个节点)

给定一个链表，删除链表的倒数第 *n* 个节点，并且返回链表的头结点。

**示例：**

```
给定一个链表: 1->2->3->4->5, 和 n = 2.

当删除了倒数第二个节点后，链表变为 1->2->3->5.
```

**说明：**

给定的 *n* 保证是有效的。

**进阶：**

你能尝试使用一趟扫描实现吗？

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
(1)struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    if (head == NULL) return head;
    int count = 0;
    struct ListNode ret, *current_node, *next_node = head;
    ret.next = head;
    while (next_node) {
        next_node = next_node->next;
        count++;
    }
    next_node = &ret;
    count -= n;
    while (count--) {
        next_node = next_node->next;
    }
    current_node = next_node->next;
    next_node->next = current_node->next;
    free(current_node);
    return ret.next;
}

(2)struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    if (!head) return head;
    struct ListNode ret, *q = &ret, *p = head;
    ret.next = head;
    while (n--) {
        p = p->next;
    }
    while (p) {
        q = q->next;
        p = p->next;
    }
    p = q->next;
    q->next = p->next;
    free(p);
    return ret.next;
}
```

#### 方法一：两次遍历算法

**思路**

我们注意到这个问题可以容易地简化成另一个问题：删除从列表开头数起的第 (L - n + 1)(L−n+1) 个结点，其中 LL是列表的长度。只要我们找到列表的长度 LL，这个问题就很容易解决。

**算法**

首先我们将添加一个哑结点作为辅助，该结点位于列表头部。哑结点用来简化某些极端情况，例如列表中只含有一个结点，或需要删除列表的头部。在第一次遍历中，我们找出列表的长度 LL。然后设置一个指向哑结点的指针，并移动它遍历列表，直至它到达第 (L - n)(L−n) 个结点那里。我们把第 (L - n)(L−n) 个结点的 `next` 指针重新链接至第 (L - n + 2)(L−n+2) 个结点，完成这个算法。

#### 方法二：一次遍历算法

**算法**

上述算法可以优化为只使用一次遍历。我们可以使用两个指针而不是一个指针。第一个指针从列表的开头向前移动 n+1n+1 步，而第二个指针将从列表的开头出发。现在，这两个指针被 nn 个结点分开。我们通过同时移动两个指针向前来保持这个恒定的间隔，直到第一个指针到达最后一个结点。此时第二个指针将指向从最后一个结点数起的第 nn 个结点。我们重新链接第二个指针所引用的结点的 `next` 指针指向该结点的下下个结点。

## LeetCode 24.Swap Nodes in Pairs(两两交换链表中的节点)

给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。

**示例:**

```
给定 1->2->3->4, 你应该返回 2->1->4->3.
```

**说明:**

- 你的算法只能使用常数的额外空间。
- **你不能只是单纯的改变节点内部的值**，而是需要实际的进行节点交换。

 ```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/*struct ListNode* swapPairs(struct ListNode* head) {
    if (head == NULL || head->next == NULL) return head;
    struct ListNode *p = head, *q = head->next, *k = head->next->next;
    head = head->next;
    while (1) {
        q->next = p;
        p->next = k;
         //判断第三指针及其下一指针是否为空，如不为空则更新头结点的下一节点
        if (k && k->next) p->next = k->next;
        p = k;
        if (p == NULL || p->next == NULL) break;
        q = p->next;
        k = q->next;
    }
    return head;
}*/
struct ListNode* swapPairs(struct ListNode* head) {
    if (head == NULL || head->next == NULL) return head;
    struct ListNode ret, *p = &ret, *q = head->next;
    ret.next = head;
    while (q) {
        p->next->next = q->next;
        q->next = p->next;
        p->next = q;
        p = q->next;
        if (q->next->next == NULL) break;
        q = q->next->next->next;
    }
    return ret.next;
}
 ```

​     