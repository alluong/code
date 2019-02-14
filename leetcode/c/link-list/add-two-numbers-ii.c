#if 0
445. Add Two Numbers II
Medium

606

84

Favorite

Share
You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Follow up:
What if you cannot modify the input lists? In other words, reversing the lists is not allowed.

Example:

Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 8 -> 0 -> 7
#endif
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *
reverse(struct ListNode *list)
{
    struct ListNode *head, *tmp;
    
    if (!list || !list->next)
        return list;
    head = NULL;
    while (list) {
        tmp = list->next;
        list->next = head;
        head = list;
        list = tmp;
    }
    return head;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *node, *head;
    int carry = 0, val;
    
    l1 = reverse(l1);
    l2 = reverse(l2);
    head = NULL;
    while (l1 || l2) {
        node = (struct ListNode *)malloc(sizeof(struct ListNode));
        if (l1 && l2) {
            val = l1->val + l2->val + carry;
            l1 = l1->next;
            l2 = l2->next;
        } else if (l1) {
            val = l1->val + carry;            
            l1 = l1->next;
        } else {
            val = l2->val + carry;
            l2 = l2->next;
        }
        node->val = val % 10;
        carry = val / 10;
        node->next = head;
        head = node;        
    }
    if (carry) {
        node = (struct ListNode *)malloc(sizeof(struct ListNode));
        node->val = carry;
        node->next = head;
        head = node;
    }
    return head;
}
