/*
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing
together the nodes of the first two lists.

Example:

Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *head, *p;
    
    if (l1 == NULL)
        return l2;
    if (l2 == NULL)
        return l1;
    if (l1->val < l2->val) {
        head = l1;
        l1 = l1->next;
    } else {
        head = l2;
        l2 = l2->next;
    }
    p = head;
    while (l1 != NULL && l2 != NULL) {
        if (l1->val < l2->val) {
            p->next = l1;
            p = p->next;
            l1 = l1->next;
        } else {
            p->next = l2;
            p = p->next;
            l2 = l2->next;
        }
    }
    if (l1 == NULL)
        p->next = l2;
    else
        p->next = l1;
    return head;
}

/* recursive solution */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    if (!l1)
        return l2;
    if (!l2)
        return l1;
    if (l1->val < l2->val) {
        /* link the next node on the smaller of l1->next or l2 */
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    } else {
        /* link the next node on the smaller of l1 or l2->next */
        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
    }
}
