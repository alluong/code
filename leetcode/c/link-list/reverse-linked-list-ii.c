#if 0
92. Reverse Linked List II
Medium

960

72

Favorite

Share
Reverse a linked list from position m to n. Do it in one-pass.

Note: 1 ≤ m ≤ n ≤ length of list.

Example:

Input: 1->2->3->4->5->NULL, m = 2, n = 4
Output: 1->4->3->2->5->NULL
#endif

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseBetween(struct ListNode* head, int m, int n) {
    int ii;
    struct ListNode *p, *pp, *q, *tmp;
    
    if (m == n)
        return head;
    
    /* pp is the node before the reverse */
    pp = NULL;
    for (ii = 1; ii < m; ii++) {
        if (!pp)
            pp = head;
        else
            pp = pp->next;
    }
    if (pp)
        p = pp->next;
    else
        p = head;
    for (ii = m; ii <= n; ii++) {
        p = p->next;
    }
    q = p;
    if (pp)
        p = pp->next;
    else
        p = head;
    
    /* reverse the nodes from m to n */
    for (ii = m; ii <= n; ii++) {
        tmp = p->next;
        p->next = q;
        q = p;
        p = tmp;
    }
    if (pp)
        pp->next = q;
    else
        head = q;
    return head;
}
