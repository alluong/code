#if 0
628. Maximum Product of Three Numbers
Easy

595

242

Favorite

Share
Given an integer array, find three numbers whose product is maximum and output the maximum product.

Example 1:

Input: [1,2,3]
Output: 6
 

Example 2:

Input: [1,2,3,4]
Output: 24
 

Note:

The length of the given array will be in range [3,104] and all elements are in the range [-1000, 1000].
Multiplication of any three numbers in the input won't exceed the range of 32-bit signed integer.
 

Accepted
60,897
Submissions
133,775
#endif

int cmpfunc(const void *a, const void *b)
{
   return (*(int *)a - *(int *)b);
}

int maximumProduct(int* nums, int numsSize) {
    int p, p0, p1, ii;
    
    if (numsSize < 3)
        return 0;
    qsort(nums, numsSize, sizeof(nums[0]), cmpfunc);
    p0 = nums[0] * nums[1] * nums[numsSize - 1];
    p1 = nums[numsSize-3] * nums[numsSize-2] * nums[numsSize-1];
    return (p0 > p1) ? p0 : p1;
}
