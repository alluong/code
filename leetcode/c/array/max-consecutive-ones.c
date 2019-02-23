#if 0
485. Max Consecutive Ones
Easy

324

291

Favorite

Share
Given a binary array, find the maximum number of consecutive 1s in this array.

Example 1:
Input: [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s.
    The maximum number of consecutive 1s is 3.
Note:

The input array will only contain 0 and 1.
The length of input array is a positive integer and will not exceed 10,000
Accepted
122,837
Submissions
225,713
#endif

int findMaxConsecutiveOnes(int* nums, int numsSize) {
    int ii, max, cur_max;
    
    max = 0;
    cur_max = 0;
    for (ii = 0; ii < numsSize; ii++) {
        if (nums[ii])
            ++cur_max;
        else {
            if (cur_max > max)
                max = cur_max;
            cur_max = 0;
        }
    }
    if (cur_max > max)
        max = cur_max;
    return max;
}
