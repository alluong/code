#if 0
147. Insertion Sort List
Medium

291

350

Favorite

Share
Sort a linked list using insertion sort.


A graphical example of insertion sort. The partial sorted list (black) initially contains only the first element in the list.
With each iteration one element (red) is removed from the input data and inserted in-place into the sorted list
 

Algorithm of Insertion Sort:

Insertion sort iterates, consuming one input element each repetition, and growing a sorted output list.
At each iteration, insertion sort removes one element from the input data, finds the location it belongs within the sorted list, and inserts it there.
It repeats until no input elements remain.

Example 1:

Input: 4->2->1->3
Output: 1->2->3->4
Example 2:

Input: -1->5->3->4->0
Output: -1->0->3->4->5
#endif

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* insertionSortList(struct ListNode* head) {
    struct ListNode *p, *pp, *q, *pq, *nq;

    if (!head || !head->next)
        /* return if 1 node or less */
        return head;
    
    /* set up the key node */
    pq = head;
    q = pq->next;
    while (q) {
        p = head;
        
        /* save next node since q coulde be moved */
        nq = q->next;
        
        /* set pp to NULL */
        pp = NULL;
        
        /* travel through list until node p is found */
        while (p->val < q->val) {
            pp = p;
            p = p->next;
        }
        
        /* do insertion if necessary */
        // if (p->val >= q->val) {/* this breaks if vals are the same */
        if (p != q) {
            pq->next = nq;
            if (!pp) {
                head = q;
                q->next = p;
            } else {
                pp->next = q;
                q->next = p;
            }           
        } else {
            /* otherwise advance pq */
            pq = q;
        }
        q = nq;
    }
    return head;
}
