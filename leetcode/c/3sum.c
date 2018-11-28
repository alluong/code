/*
Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:

The solution set must not contain duplicate triplets.
*/
int compare(const void *a, const void *b)
{
    return *(const int *)a - *(const int *)b;
}

/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool
add_output(int **result, int index, int a, int b, int c)
{
    int ii;
    int *arr;
    
    for (ii = 0; ii < index; ii++) {
        if (result[ii][0] == a && result[ii][1] == b && result[ii][2] == c) {
            return false;
        }
    }
    arr = (int *)malloc(sizeof(int) * 3);
    arr[0] = a;
    arr[1] = b;
    arr[2] = c;
    result[index] = arr;
    return true;
}

int** threeSum(int* nums, int numsSize, int* returnSize) {
    int sum, ii, left, right, **result;
    
    // sort the array
    *returnSize = 0;
    result = (int **)malloc(100000 * sizeof(int *));
    qsort(nums, numsSize, 4, compare);
    for (ii = 0; ii < numsSize - 1; ii++) {
        sum = nums[ii];
        left = ii + 1;
        right = numsSize - 1;
        
        // find all pairs equal to -sum
        while (left < right) {
            if (sum + nums[left] + nums[right] == 0) {
                // found it, store it and advance left and right
                if (add_output(result, *returnSize, nums[ii], nums[left], nums[right])) {
                    ++(*returnSize);
                }
                
                // advance both pointers regardless
                ++left;
                --right;
            } else if (sum + nums[left] + nums[right] < 0)
                ++left;
            else
                --right;
        }
    }
    return result;
}
