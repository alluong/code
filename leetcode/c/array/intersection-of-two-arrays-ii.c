#if 0
350. Intersection of Two Arrays II
Easy

604

216

Favorite

Share
Given two arrays, write a function to compute their intersection.

Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2,2]
Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [4,9]
Note:

Each element in the result should appear as many times as it shows in both arrays.
The result can be in any order.
Follow up:

What if the given array is already sorted? How would you optimize your algorithm?
What if nums1's size is small compared to nums2's size? Which algorithm is better?
What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?
Accepted
180,054
Submissions
384,640
#endif

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int cmpfunc (const void *a, const void *b)
{
    /* can't do
       return *(int *)a - *(int *)b;
       due to overflow
     */
    if (*(int *)a > *(int *)b)
       return true;
    return false;
}

int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int ii, jj, *arr;
    
    qsort(nums1, nums1Size, sizeof(int), cmpfunc);
    qsort(nums2, nums2Size, sizeof(int), cmpfunc);
    ii = jj = 0;
    *returnSize = 0;
    arr = (int *)malloc(sizeof(int) * nums1Size);
    while (ii < nums1Size && jj < nums2Size) {
        if (nums1[ii] == nums2[jj]) {
            arr[*returnSize] = nums1[ii];
            ++(*returnSize);
            ++ii;
            ++jj;
        } else if (nums1[ii] < nums2[jj])
            ++ii;
        else
            ++jj;
    }
    return arr;
}
