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
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func deleteDuplicates(head *ListNode) *ListNode {
    var p, q *ListNode
    
    if head == nil || head.Next == nil {
        return head
    }
    for p = head; p != nil; p = p.Next {
        for q = p; q.Next != nil; {
            if p.Val == q.Next.Val {
                q.Next = q.Next.Next
            } else {
                q = q.Next
            }
        }
    }
    return head
}
