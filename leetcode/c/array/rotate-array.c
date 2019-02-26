#if 0
Given an array, rotate the array to the right by k steps, where k is non-negative.

Example 1:

Input: [1,2,3,4,5,6,7] and k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
Example 2:

Input: [-1,-100,3,99] and k = 2
Output: [3,99,-1,-100]
Explanation: 
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]
Note:

Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.
Could you do it in-place with O(1) extra space?
Accepted
265,275
Submissions
919,354
#endif

void rotate(int* nums, int numsSize, int k) {
    int *arr, ii, jj;
    
    if (numsSize <= 0)
        return;
        
    /* !!!watch out that k could be greater than length of array */
    k = k % numsSize;

    /* store the elements to be rotated */
    arr = (int *)malloc(sizeof(int) * k);
    for (ii = numsSize - k, jj = 0; ii < numsSize; ii++, jj++) {
        arr[jj] = nums[ii];
    }
    
    /* copy the elements starting at the end */
    for (ii = numsSize - k - 1; ii >= 0; ii--) {
        nums[ii + k] = nums[ii];
    }
    
    /* copy the stored elements */
    for (ii = 0; ii < k; ii++) {
        nums[ii] = arr[ii];
    }
    free(arr);
} 
