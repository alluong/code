#if 0
283. Move Zeroes
Easy

1759

67

Favorite

Share
Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Example:

Input: [0,1,0,3,12]
Output: [1,3,12,0,0]
Note:

You must do this in-place without making a copy of the array.
Minimize the total number of operations.
Accepted
418,740
Submissions
782,166
#endif

void
swap(int *a, int *b)
{
    int tmp;
    
    tmp = *a;
    *a = *b;
    *b = tmp;
}

void moveZeroes(int* nums, int numsSize) {
    int ii, jj, last;
    
    if (numsSize <= 0)
        return;
    
    /* find the last non-zero */
    last = 0;
    for (ii = numsSize - 1; ii >= 0; ii--) {
        if (nums[ii]) {
            last = ii;
            break;
        }
    }
    
    /* iterate until == last */
    for (ii = 0; ii <= last; ii++) {
        if (!nums[ii]) {
            for (jj = ii + 1; jj <= last; jj++) {
                if (nums[jj]) {
                    swap(nums + ii, nums + jj);
                    break;
                }
            }
        }
    }
}
