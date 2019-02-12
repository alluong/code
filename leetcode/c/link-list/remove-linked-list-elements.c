/*
Remove all elements from a linked list of integers that have value val.

Example:

Input:  1->2->6->3->4->5->6, val = 6
Output: 1->2->3->4->5
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode *p, *temp, *pp, *new_head;
    
    if (!head)
        return head;
    new_head = head;
    p = new_head;
    pp = p;
    while (p) {
        if (p->val == val) {
            if (p == new_head) {
                temp = p;
                p = p->next;
                new_head = p;
            } else {
                temp = p;
                p = p->next;
                pp->next = p;
            }
            free(temp);
        } else {
            pp = p;
            p = p->next;        
        }
    }
    return new_head;
}
