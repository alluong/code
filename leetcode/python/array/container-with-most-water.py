"""
Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai).
n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two
lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container and n is at least 2.
The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.

 

Example:

Input: [1,8,6,2,5,4,8,3,7]
Output: 49
"""

class Solution:
    def maxArea(self, height):
       
        
        # get the maximum height of the list
        if (len(height) == 0):
            return 0
        max_height = max(height)
        max_area = 0
        
        # start on the most left and right ends
        left = 0
        right = len(height) - 1
        cur_height = 0
        while (left != right and cur_height <= max_height):
            if (height[left] >= cur_height and height[right] >= cur_height):
                # found both left and right are taller, set the current height
                # and calculate area
                cur_height = min(height[left], height[right])
                area = (right - left) * cur_height
                max_area = max(area, max_area)

            # advance the lower edge
            if (height[left] < height[right]):
                left += 1
            else:
                right -= 1
        return max_area
