"""
Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target.
Return the sum of the three integers. You may assume that each input would have exactly one solution.

Example:

Given array nums = [-1, 2, 1, -4], and target = 1.

The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
"""
class Solution:
    def threeSumClosest(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        
        if (len(nums) < 3):
            return []
        
        # sort the numbers
        nums.sort()

        # set closest_dist to be the largest number
        closest_dist = float("inf")
        for index in range(len(nums) - 2):
            start = index + 1
            end = len(nums) - 1
            while (start < end):
                total = nums[index] + nums[start] + nums[end]
                result = target - total
                
                # if result is greater than 0, move start pointer
                if (result > 0):
                    start += 1
                    
                # if result is less than 0, move end pointer
                elif (result < 0):
                    end -= 1
                else:
                    return target
                dist = abs(total - target)
                if (dist < closest_dist):
                    # update closest and store the result
                    closest = total
                    closest_dist = dist
        return closest
