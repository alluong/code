/*
You are given two non-empty linked lists representing two non-negative integers. The digits
are stored in reverse order and each of their nodes contain a single digit. Add the two
numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *p, *head, *node;
    int value, carry;
    
    p = head = NULL;
    carry = 0;
    while (l1 || l2) {
        int v1 = l1 ? l1->val : 0;
        int v2 = l2 ? l2->val : 0;
        
        value = v1 + v2 + carry;
        node = malloc(sizeof(*node));
        node->val = value % 10;
        node->next = NULL;
        carry = value / 10;
        if (!p) {
            p = node;
            head = p;
        } else {
            p->next = node;
            p = p->next;
        }
        l1 = l1 ? l1->next : l1;
        l2 = l2 ? l2->next : l2;
    }
    if (carry) {
        node = malloc(sizeof(*node));
        node->val = carry;
        node->next = NULL;
        p->next = node;
    }
    return head;    
}
