"""
Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:

The solution set must not contain duplicate triplets.

Example:

Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
"""

class Solution:
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
       
        # sort the numbers
        nums.sort()

        # resultant array to be returned
        result = []
        for ii in range(len(nums)):
            target = nums[ii]*-1
            start = ii + 1
            end = len(nums) - 1
            while (start < end):
                if (nums[start] + nums[end] < target):
                    start += 1
                elif (nums[start] + nums[end] > target):
                    end -= 1
                else:
                    result.append([nums[ii], nums[start], nums[end]])
                    start += 1
        
        # remove duplicate
        res = []
        for ii, res1 in enumerate(result):
            if res1 not in res:
                res += [res1]
        return res
