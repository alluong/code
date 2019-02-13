'''
There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

You may assume nums1 and nums2 cannot be both empty.

Example 1:

nums1 = [1, 3]
nums2 = [2]

The median is 2.0
Example 2:

nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5
'''

def find_median(nums):
    if len(nums) == 0:
        return 0.0
    if len(nums) % 2:
        median = nums[len(nums) // 2]
    else:
        median = (nums[len(nums) // 2 - 1] + nums[len(nums) // 2]) / 2
    return median

class Solution:
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        
        nums3 = sorted(nums1 + nums2)
        return find_median(nums3)
