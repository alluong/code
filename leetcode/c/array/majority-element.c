
#if 0
169. Majority Element
Easy

1404

128

Favorite

Share
Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.

Example 1:

Input: [3,2,3]
Output: 3
Example 2:

Input: [2,2,1,1,1,2,2]
Output: 2
Accepted
345,959
Submissions
673,243
#endif

int cmpfunc (const void *a, const void *b)
{
   return (*(int *)a - *(int *)b);
}

int majorityElement(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(nums[0]), cmpfunc);
    /*
     * the majority element appears more than half the time, so the middle element after sorting
     * must contain the majority element
     */
    return nums[numsSize/2];
}
