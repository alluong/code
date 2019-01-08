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
