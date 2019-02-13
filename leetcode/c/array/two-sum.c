/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target) {
    int *res, ii, jj;
    
    if (numsSize < 2)
        return NULL;
    res = malloc(2 * sizeof(int));
    for (ii = 0; ii < numsSize - 1; ii++) {
        for (jj = ii + 1; jj < numsSize; jj++) {
            if (nums[ii] + nums[jj] == target) {
                res[0] = ii;
                res[1] = jj;
                return res;
            }
        }
    }
    return NULL;
}
