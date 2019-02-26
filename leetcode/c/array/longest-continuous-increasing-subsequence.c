#if 0
674. Longest Continuous Increasing Subsequence
Easy

401

91

Favorite

Share
Given an unsorted array of integers, find the length of longest continuous increasing subsequence (subarray).

Example 1:
Input: [1,3,5,4,7]
Output: 3
Explanation: The longest continuous increasing subsequence is [1,3,5], its length is 3. 
Even though [1,3,5,7] is also an increasing subsequence, it's not a continuous one where 5 and 7 are separated by 4. 
Example 2:
Input: [2,2,2,2,2]
Output: 1
Explanation: The longest continuous increasing subsequence is [2], its length is 1. 
Note: Length of the array will not exceed 10,000.

Accepted
58,339
Submissions
133,362
#endif

int findLengthOfLCIS(int* nums, int numsSize) {
    int ii, inc, val, max;
    
    if (numsSize <= 0)
        return 0;
    val = nums[0];
    max = inc = 1;
    for (ii = 1; ii < numsSize; ii++) {
        if (nums[ii] > val) {
            ++inc;
            if (max < inc)
                max = inc;
        } else {
            inc = 1;
        }
        val = nums[ii];
    }
    return max;
}
