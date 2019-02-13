#if 0
Given a singly linked list, determine if it is a palindrome.

Example 1:

Input: 1->2
Output: false
Example 2:

Input: 1->2->2->1
Output: true
Follow up:
Could you do it in O(n) time and O(1) space?
#endif

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool isPalindrome(struct ListNode* head) {
    struct ListNode *l1, *l2, *p, *q;

    if (!head)
        return true;

    /* split the list */
    l1 = l2 = head;
    while (l2) {
        l2 = l2->next;
        
        /* advance l1 iff the next node is not NULL */
        if (l2 && l2->next) {
            l1 = l1->next;
            l2 = l2->next;
        }
    }
    l2 = l1->next;
    l1->next = NULL;

    /* reverse l2 */
    p = l2;
    q = NULL;
    while (p) {
        l2 = p->next;
        p->next = q;
        q = p;
        p = l2;
    }
    l1 = head;
    l2 = q;

    
    /* compare the 2 link list */
    while (l2) {
        if (l2->val != l1->val)
            return false;
        l1 = l1->next;
        l2 = l2->next;
    }
    return true;
}
