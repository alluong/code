#if 0
448. Find All Numbers Disappeared in an Array
Easy

1419

135

Favorite

Share
Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.

Find all the elements of [1, n] inclusive that do not appear in this array.

Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.

Example:

Input:
[4,3,2,7,8,2,3,1]

Output:
[5,6]
Accepted
134,681
Submissions
255,861
#endif

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int cmpfunc (const void *a, const void *b)
{
   return (*(int *)a - *(int *)b);
}

int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize) {
    int *arr, ii, *res;
    
    arr = (int *)malloc(sizeof(int) * (numsSize + 1));
    memset(arr, 0, sizeof(int) * (numsSize + 1));
    for (ii = 0; ii < numsSize; ii++) {
        arr[nums[ii]] = 1;
    }
    *returnSize = 0;
    res = (int *)malloc(sizeof(int) * (numsSize + 1));
    for (ii = 1; ii <= numsSize; ii++) {
        if (!arr[ii]) {
            res[*returnSize] = ii;
            ++(*returnSize);
        }
    }
    return res;
}
