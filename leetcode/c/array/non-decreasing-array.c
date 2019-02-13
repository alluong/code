#if 0
665. Non-decreasing Array
Easy

Given an array with n integers, your task is to check if it could become non-decreasing by modifying at most 1 element.

We define an array is non-decreasing if array[i] <= array[i + 1] holds for every i (1 <= i < n).

Example 1:
Input: [4,2,3]
Output: True
Explanation: You could modify the first 4 to 1 to get a non-decreasing array.
Example 2:
Input: [4,2,1]
Output: False
Explanation: You can't get a non-decreasing array by modify at most one element.
Note: The n belongs to [1, 10,000].
#endif

bool checkPossibility(int* nums, int numsSize) {
    int ii, count;
    
    count = 0;
    for (ii = 0; ii < numsSize - 1; ii++) {
        if (nums[ii] > nums[ii + 1]) {
            ++count;
            
            /* if we have more than 2 decrease, return false */
            if (count >= 2)
                return false; 
            /*
             * handle test case [2,3,3,2,4]
             * return false
             * if and only if the previous element is greater than the next
             * AND
             * the current element is greate than the +2 element ahead
             */
            if (ii && nums[ii - 1] > nums[ii + 1] &&
                ii + 2 < numsSize && nums[ii] > nums[ii + 2])
                return false;
        }
    }
    return true;
}
