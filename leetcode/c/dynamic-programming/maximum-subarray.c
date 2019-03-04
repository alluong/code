#if 0
53. Maximum Subarray
Easy

3698

131

Favorite

Share
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Example:

Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
Follow up:

If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.

Accepted
467,655
Submissions
1,092,449
#endif

int maxSubArray(int* nums, int numsSize) {
    int *dp, ii, max;
 
    /* allocate array for dp */
    dp = (int *)malloc(sizeof(int) * numsSize);
    
    /* initialize first element */
    max = dp[0] = nums[0];
    for (ii = 1; ii < numsSize; ii++) {
        if (dp[ii - 1] > 0)
            /* if previous stored value > 0, add to current */
            dp[ii] = nums[ii] + dp[ii - 1];
        else
            /* set to current value of nums[ii] */
            dp[ii] = nums[ii];
        
        /* update max */
        max = max > dp[ii] ? max : dp[ii];
    }
    return max;
}
