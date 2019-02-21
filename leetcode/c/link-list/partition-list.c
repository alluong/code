#if 0
86. Partition List
Medium

552

146

Favorite

Share
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

Example:

Input: head = 1->4->3->2->5->2, x = 3
Output: 1->2->2->4->3->5
Accepted
151,710
Submissions
419,339
#endif

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* partition(struct ListNode* head, int x) {
    struct ListNode *pp, *p, *pq, *q, *new, *nn;
    
    if (!head || !head->next)
        return head;
    pp = NULL;
    p = head;
    
    /* traverse up to node x
     * p contains val > x
     * pp is the previous pointer
     */
    while (p && p->val < x) {
        pp = p;
        p = p->next;
    }
    
    /* remove all the nodes smaller than x */
    pq = p;
    
    /* p could be at end of list */
    if (p) {
        q = p->next;
        new = NULL;
        while (q) {
            if (q->val < x) {
                pq->next = q->next;
                if (!new) {
                    new = q;
                    nn = new;
                } else {
                    nn->next = q;
                    nn = nn->next;
                }
            } else {
                pq = q;
            }
            q = q->next;
        }
    }
    
    /* combine the two lists */
    if (!pp) {
        /* pp is NULL, we could have a new head */
        if (new) {
            nn->next = head;
            head = new;
        }
    } else {
        if (nn) {
            /* attach the front */
            pp->next = new;
            
            /* attach the back */
            nn->next = p;
        }
    }
    return head;
}
