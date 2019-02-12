#if 0
Given a linked list, rotate the list to the right by k places, where k is non-negative.

Example 1:

Input: 1->2->3->4->5->NULL, k = 2
Output: 4->5->1->2->3->NULL
Explanation:
rotate 1 steps to the right: 5->1->2->3->4->NULL
rotate 2 steps to the right: 4->5->1->2->3->NULL
Example 2:

Input: 0->1->2->NULL, k = 4
Output: 2->0->1->NULL
Explanation:
rotate 1 steps to the right: 2->0->1->NULL
rotate 2 steps to the right: 1->2->0->NULL
rotate 3 steps to the right: 0->1->2->NULL
rotate 4 steps to the right: 2->0->1->NULL
#endif

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* rotateRight(struct ListNode* head, int k) {
    int len, ii;
    struct ListNode *p, *q;
    
    if (!head)
        return NULL;
    p = head;
    len = 0;
    while (p != NULL) {
        ++len;
        p = p->next;
    }
    k = k % len;
    if (k) {
        p = head;
        q = NULL;
        while (p->next) {
            if (k > 0)
                k--;
            if (k <= 0) {
                if (!q)
                    q = head;
                else
                    q = q->next;
            }
            p = p->next;
        }
        p->next = head;
        head = q->next;
        q->next = NULL;
    }
    return head;
}
