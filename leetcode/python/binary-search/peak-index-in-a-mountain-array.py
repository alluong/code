"""
852. Peak Index in a Mountain Array
Easy

239

548

Favorite

Share
Let's call an array A a mountain if the following properties hold:

A.length >= 3
There exists some 0 < i < A.length - 1 such that A[0] < A[1] < ... A[i-1] < A[i] > A[i+1] > ... > A[A.length - 1]
Given an array that is definitely a mountain, return any i such that A[0] < A[1] < ... A[i-1] < A[i] > A[i+1] > ... > A[A.length - 1].

Example 1:

Input: [0,1,0]
Output: 1
Example 2:

Input: [0,2,1,0]
Output: 1
Note:

3 <= A.length <= 10000
0 <= A[i] <= 10^6
A is a mountain, as defined above.
Accepted
60,277
Submissions
87,294
"""

class Solution:
    def peakIndexInMountainArray(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        
        left = 0
        right = len(A) - 1
        mid = (left + right) // 2
        
        # do binary search
        while (mid > left and mid < right):
            if (A[mid] > A[mid - 1]):
                left = mid
            else:
                right = mid
            mid = (left + right) // 2
        return mid
