#if 0
209. Minimum Size Subarray Sum
Medium

954

63

Favorite

Share
Given an array of n positive integers and a positive integer s, find the minimal length of a contiguous subarray of which the sum ≥ s. If there isn't one, return 0 instead.

Example: 

Input: s = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: the subarray [4,3] has the minimal length under the problem constraint.
Follow up:
If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log n). 
Accepted
163,125
Submissions
476,214
#endif

int minSubArrayLen(int s, int* nums, int numsSize) {
#if 0 /* brute force */
    int ii, jj, sum, len, min;
    
    min = numsSize + 1;
    for (ii = 0; ii < numsSize; ii++) {
        sum = nums[ii];
        len = 1;
        if (sum == s)
            return len;
        for (jj = ii + 1; jj < numsSize; jj++) {
            sum += nums[jj];
            ++len;
            if (sum == s) {
                if (min > len)
                    min = len;
            }                
            if (sum > s)
                break;
        }
    }
    return min != numsSize + 1 ? min : 0;
#else
    int start, end, sum, min;
    
    start = end = 0;
    min = numsSize + 1;
    sum = 0;
    while (end < numsSize) {
        sum += nums[end];
        ++end;
        
        /* if sum is greater than s, delete elements at start */
        while (sum > s && start < end) {
            sum -= nums[start];
            start++;
        }
        if (sum == s) {
            if (end - start < min) {
                min = end - start;
            }
        }
    }
    return min != numsSize + 1 ? min : 0;
#endif
}
