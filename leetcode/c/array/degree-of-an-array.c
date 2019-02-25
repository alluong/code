#if 0
697. Degree of an Array
Easy

446

360

Favorite

Share
Given a non-empty array of non-negative integers nums, the degree of this array is defined as the maximum frequency of any one of its elements.

Your task is to find the smallest possible length of a (contiguous) subarray of nums, that has the same degree as nums.

Example 1:
Input: [1, 2, 2, 3, 1]
Output: 2
Explanation: 
The input array has a degree of 2 because both elements 1 and 2 appear twice.
Of the subarrays that have the same degree:
[1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
The shortest length is 2. So return 2.
Example 2:
Input: [1,2,2,3,1,4,2]
Output: 6
Note:

nums.length will be between 1 and 50,000.
nums[i] will be an integer between 0 and 49,999.
Accepted
41,421
Submissions
84,445
#endif

int cmpfunc (const void *a, const void *b)
{
   return (*(int *)a - *(int *)b);
}

int findShortestSubArray(int* nums, int numsSize) {
    int *arr = (int *)malloc(sizeof(int) * numsSize);
    int *max_ele = (int *)malloc(sizeof(int) * numsSize);
    int ii, jj, deg, min_ele, num_ele, max_deg, cur, count;
    
    if (!numsSize)
        return 0;    
    arr = memcpy(arr, nums, sizeof(int) * numsSize);
    qsort(arr, numsSize, sizeof(arr[0]), cmpfunc);
    deg = 0;
    max_deg = 0;
    cur = arr[0];
    for (ii = 0; ii < numsSize; ii++) {
        if (arr[ii] == cur) {
            ++deg;
            if (max_deg < deg) {
                count = 1;
                max_ele[count - 1] = arr[ii];
                max_deg = deg;
            } else if (max_deg == deg) {
                max_ele[count] = arr[ii];
                ++count;
            }
        } else {
            cur = arr[ii];
            deg = 1;
        }
    }
    min_ele = numsSize;
    for (jj = 0; jj < count; jj++) {
        num_ele = numsSize;
        ii = 0;
        while (nums[ii] != max_ele[jj]) {
            ii++;
            num_ele--;
        }
        ii = numsSize - 1;
        while (nums[ii] != max_ele[jj]) {
            ii--;
            num_ele--;
        }
        if (min_ele > num_ele)
            min_ele = num_ele;
    }
    free(arr);
    free(max_ele);
    return min_ele;
}
