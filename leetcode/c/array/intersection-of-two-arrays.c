#if 0
349. Intersection of Two Arrays
Easy

346

714

Favorite

Share
Given two arrays, write a function to compute their intersection.

Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]
Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]
Note:

Each element in the result must be unique.
The result can be in any order.
 

Accepted
197,125
Submissions
372,349
#endif

int cmpfunc (const void *a, const void *b)
{
   return (*(int *)a - *(int *)b);
}

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int *arr, size, ii, jj, kk, num1, num2;

    if (!nums1Size || !nums2Size) {
        *returnSize = 0;
        return NULL;
    }
    qsort(nums1, nums1Size, sizeof(int), cmpfunc);
    qsort(nums2, nums2Size, sizeof(int), cmpfunc);
    
    /* allocate memory */
    size = (nums1Size < nums2Size) ? nums1Size : nums2Size;
    arr = (int *)malloc(sizeof(int) * size);
    
    /* init */
    ii = kk = 0;
    while (ii < nums1Size) {
        num1 = nums1[ii];
        jj = 0;
        while (jj < nums2Size && nums1[ii] >= nums2[jj]) {
            if (nums1[ii] == nums2[jj]) {
                /* check and see if it is the same value as the previous one */
                if (kk == 0 || nums1[ii] != arr[kk - 1]) {
                    arr[kk] = nums1[ii];
                    ++kk;
                }
            }
            ++jj;
        }
        ++ii;
    }
    *returnSize = kk;
    return arr;
}
