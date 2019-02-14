#if 0
Given a linked list, swap every two adjacent nodes and return its head.

You may not modify the values in the list's nodes, only nodes itself may be changed.

 

Example:

Given 1->2->3->4, you should return the list as 2->1->4->3.
#endif

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
    struct ListNode *p, *q, *tmp, *new;
    
    if (!head || !head->next)
        return head;
    p = head;
    new = NULL;
    while (p && p->next) {
        tmp = p->next->next;
        if (!new) {
            new = p->next;
            new->next = p;
            q = new->next;
            q->next = NULL;
        } else {
            q->next = p->next;
            q->next->next = p;
            q = p;
        }
        p = tmp;
    }
    if (p)
        q->next = p;
    else
        q->next = NULL;
    return new;
}
