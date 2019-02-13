# You are given two non-empty linked lists representing two non-negative integers. The digits are
# stored in reverse order and each of their nodes contain a single digit. Add the two numbers and
# return it as a linked list.

# You may assume the two numbers do not contain any leading zero, except the number 0 itself.

# Example:

# Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
# Output: 7 -> 0 -> 8
# Explanation: 342 + 465 = 807.

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        
        carry = 0
        head = None
        while l1 or l2:
            if l1 and l2:
                # both link list are not empty
                node = ListNode(int((l1.val + l2.val + carry) % 10))
                if head == None:
                    head = node
                    tmp = head
                else:
                    tmp.next = node
                    tmp = tmp.next
                    
                # floor division
                carry = (l1.val + l2.val + carry) // 10

                # advance pointer
                l1 = l1.next
                l2 = l2.next
            elif l1:
                # list1 is not empty, list 2 is empty
                if carry:
                    node = ListNode(int((l1.val + carry) % 10))
                    
                    # floor division
                    carry = (l1.val + carry) // 10
                else:
                    node = l1
                    carry = 0
                if head == None:
                    head = node
                    tmp = head
                else:
                    tmp.next = node
                    tmp = tmp.next

                if carry:
                    # advance pointer
                    l1 = l1.next
                else:
                    tmp.next = l1.next
                    break
            elif l2:
                # list1 is empy, list2 is not empty
                if carry:
                    node = ListNode(int((l2.val + carry) % 10))
                    
                    # floor division
                    carry = (l2.val + carry) // 10
                else:
                    node = l2
                    carry = 0
                if head == None:
                    head = node
                    tmp = head
                else:
                    tmp.next = node
                    tmp = tmp.next

                if carry:
                    # advance pointer
                    l2 = l2.next
                else:
                    tmp.next = l2.next
                    break
        if carry:
            node = ListNode(1)
            tmp.next = node
        return head
        
