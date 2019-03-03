/*
Reverse a singly linked list.

Example:

Input: 1->2->3->4->5->NULL
Output: 5->4->3->2->1->NULL
Follow up:

A linked list can be reversed either iteratively or recursively. Could you implement both?
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode *p, *q, *temp;
    
    if (!head || !head->next)
        return head;
    p = head;
    q = head->next;
    p->next = NULL;
    while (q != NULL) {
        temp = q->next;
        q->next = p;
        p = q;
        q = temp;
    }
    return p;
}

/* recursion implementation */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode *rest;
    
    /* list is empty */
    if (!head)
        return NULL;
    
    /* list has 1 node */
    if (!head->next)
        return head;
    
    /* recursive call until reaching last node */
    rest = reverseList(head->next);

    /* head is the link node before "rest" since head->rest == "rest" */
    head->next->next = head;
    head->next = NULL;
    return rest;
}
