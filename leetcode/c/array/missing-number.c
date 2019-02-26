#if 0
268. Missing Number
Easy

764

1174

Favorite

Share
Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.

Example 1:

Input: [3,0,1]
Output: 2
Example 2:

Input: [9,6,4,2,3,5,7,0,1]
Output: 8
Note:
Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?

Accepted
245,934
Submissions
517,998
#endif

int missingNumber(int* nums, int numsSize) {
    int total, ii;

    total = numsSize * (numsSize + 1) / 2;
    for (ii = 0; ii < numsSize; ii++)
        total -= nums[ii];
    return total;
}
