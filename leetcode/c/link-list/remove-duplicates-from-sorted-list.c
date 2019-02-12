/*
Given a sorted linked list, delete all duplicates such that each element appear only once.

Example 1:

Input: 1->1->2
Output: 1->2
Example 2:

Input: 1->1->2->3->3
Output: 1->2->3
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode *p, *q, *dup;
    
    if (!head || !head->next)
        return head;
    p = head;
    while (p != NULL) {
        q = p;
        
        // start on the next element
        while (q->next != NULL) {
            if (p->val == q->next->val) {
                dup = q->next;
                q->next = q->next->next;
                free(dup);
            } else {
                q = q->next;
            }
        }
        
        // advance linked list
        p = p->next;
    }
    return head;
}
