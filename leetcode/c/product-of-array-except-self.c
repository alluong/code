/*
Given an array nums of n integers where n > 1,  return an array output such that output[i] is equal to the product
of all the elements of nums except nums[i].

Example:

Input:  [1,2,3,4]
Output: [24,12,8,6]
Note: Please solve it without division and in O(n).

Follow up:
Could you solve it with constant space complexity? (The output array does not count as extra space for the purpose
of space complexity analysis.)
*/
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    int *product = (int *)malloc(sizeof(int) * numsSize);
    int *left = (int *)malloc(sizeof(int) * numsSize);
    int *right = (int *)malloc(sizeof(int) * numsSize);
    int ii;

    *returnSize = numsSize;
    left[0] = 1;
    for (ii = 1; ii < numsSize; ii++) {
        left[ii] = left[ii-1] * nums[ii-1];
    }
    right[numsSize-1] = 1;
    for (ii = numsSize-2; ii >= 0; ii--) {
        right[ii] = right[ii+1] * nums[ii+1];
    }
    for (ii = 0; ii < numsSize; ii++) {
        product[ii] = left[ii] * right[ii];
    }
    return product;
}
