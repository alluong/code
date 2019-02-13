/*
Remove all elements from a linked list of integers that have value val.

Example:

Input:  1->2->6->3->4->5->6, val = 6
Output: 1->2->3->4->5
*/
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func removeElements(head *ListNode, val int) *ListNode {
    var p, pp, new_head *ListNode
    
    if head == nil {
        return head
    }
    new_head = head
    p = new_head
    pp = p
    for ; p != nil; {
        if p.Val == val {
            // remove element p          
            if p == new_head {
                // p is at head of list
                p = p.Next
                new_head = p
            } else {
                p = p.Next
                pp.Next = p
            }
        } else {
            pp = p
            p = p.Next
        }
    }
    return new_head
}
