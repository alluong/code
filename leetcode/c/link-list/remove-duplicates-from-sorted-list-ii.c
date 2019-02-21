#if 0
82. Remove Duplicates from Sorted List II
Medium

678

66

Favorite

Share
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

Example 1:

Input: 1->2->3->3->4->4->5
Output: 1->2->5
Example 2:

Input: 1->1->1->2->3
Output: 2->3
Accepted
167,210
Submissions
521,080
#endif

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode *p, *pp, *new, *nn;
    int val;
    bool flag = false;
    
    if (!head || !head->next)
        return head;
    pp = head;
    val = pp->val;
    p = pp->next;
    
    /* set up new list */
    new = nn = NULL;
    while (p) {
        if (p->val != val) {
            val = p->val;
            if (!flag) {
                pp->next = NULL;
                if (!new) {
                    /* attach to head of new list */
                    new = pp;
                    nn = new;
                } else {
                    /* attach to tail of new list */
                    nn->next = pp;
                    nn = nn->next;
                }
            } else {
                flag = false;
                free(pp);
            }
        } else {
            free(pp);
            flag = true;
        }
        
        /* advance pointers */
        pp = p;
        p = p->next;
    }
    
    /* add/free last node as necessary */
    if (!flag) {
        if (nn && nn->val != pp->val)
            nn->next = pp;
        else
            new = pp;
    } else {
        free(pp);   
    }
    return new;
}
