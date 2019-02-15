#if 0
142. Linked List Cycle II
Medium

1179

80

Favorite

Share
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

To represent a cycle in the given linked list, we use an integer pos which represents the position (0-indexed) in the linked list where tail connects to. If pos is -1, then there is no cycle in the linked list.

Note: Do not modify the linked list.

 

Example 1:

Input: head = [3,2,0,-4], pos = 1
Output: tail connects to node index 1
Explanation: There is a cycle in the linked list, where tail connects to the second node.


Example 2:

Input: head = [1,2], pos = 0
Output: tail connects to node index 0
Explanation: There is a cycle in the linked list, where tail connects to the first node.


Example 3:

Input: head = [1], pos = -1
Output: no cycle
Explanation: There is no cycle in the linked list.


 

Follow up:
Can you solve it without using extra space?
#endif

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) {
    struct ListNode *slow, *fast, *p;
    
    if (!head)
        return NULL;
    fast = slow = head;
    while (fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
            break;
    }
    if (!fast || !fast->next)
        /* no loop */
        return NULL;
    
    /*
     * the reason the below logic works is that if slow and fast start at the intersect,
     * then it will always end up at the intersect
     * advancing from head to the intersect means that fast has that many nodes ahead of
     * slow and hence, they will meet again at that same distance before the intersect
     */    
    p = head;
    while (p != slow) {
        p = p->next;
        slow = slow->next;
    }
    return p;
}
