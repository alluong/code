"""
Given a linked list, remove the n-th node from the end of list and return its head.

Example:

Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:

Given n will always be valid.
"""

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def removeNthFromEnd(self, head, n):
        """
        :type head: ListNode
        :type n: int
        :rtype: ListNode
        """
        # to do a 1 pass, keep a running pointer that is n behind the current pointer
        cur = head
        
        # tracking ptr that is n behind cur
        track = cur
        
        # prev pointer that is 1 behind track
        prev = None
        behind = 0
        while (cur):
            cur = cur.next
            behind += 1
            if (behind > n):
                prev = track
                track = track.next
        if (prev == None):
            # removing first node
            prev = track.next
            head = prev
        else:
            prev.next = track.next
        return head
