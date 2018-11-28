/*
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing
together the nodes of the first two lists.

Example:

Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4
*/
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func mergeTwoLists(l1 *ListNode, l2 *ListNode) *ListNode {
    var head, p *ListNode;
    
    if l1 == nil {
        return l2
    }
    if l2 == nil {
        return l1
    }
    if l1.Val < l2.Val {
        head = l1
        l1 = l1.Next
    } else {
        head = l2
        l2 = l2.Next
    }
    p = head
    for ; l1 != nil && l2 != nil; {
        if l1.Val < l2.Val {
            p.Next = l1
            p = p.Next
            l1 = l1.Next
        } else {
            p.Next = l2
            p = p.Next
            l2 = l2.Next
        }
    }
    if l1 == nil {
        p.Next = l2
    } else {
        p.Next = l1
    }
    return head
}
