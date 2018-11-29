/*
Reverse a singly linked list.

Example:

Input: 1->2->3->4->5->NULL
Output: 5->4->3->2->1->NULL
Follow up:

A linked list can be reversed either iteratively or recursively. Could you implement both?
*/
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func reverseList(head *ListNode) *ListNode {
	var p, q, temp *ListNode
    
    if head == nil || head.Next == nil {
        return head
    }
    p = head
    q = p.Next
    p.Next = nil
    for ; q != nil; {
        // save pointer for next element
        temp = q.Next
        q.Next = p
        p = q
        q = temp
    }
    return p
}
