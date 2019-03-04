#if 0
75. Sort Colors
Medium

1387

136

Favorite

Share
Given an array with n objects colored red, white or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note: You are not suppose to use the library's sort function for this problem.

Example:

Input: [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
Follow up:

A rather straight forward solution is a two-pass algorithm using counting sort.
First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.
Could you come up with a one-pass algorithm using only constant space?
Accepted
292,238
Submissions
707,230
#endif

void sortColors(int* nums, int numsSize) {
#if 0 /* counting sort */
    int ii, jj, kk, arr[3];
    
    memset(arr, 0, sizeof(arr));
    for (ii = 0; ii < numsSize; ii++) {
        ++arr[nums[ii]];
    }
    kk = 0;
    for (ii = 0; ii < 3; ii++) {
        for (jj = 0; jj < arr[jj]; jj++) {
            nums[kk] = ii;
            ++kk;
        }
    }
#else
    /* dutch national flag problem */
    int low, mid, high, tmp;
    
    low = mid = 0;
    high = numsSize - 1;
    while (mid <= high) {
        switch (nums[mid]) {
            case 0:
                tmp = nums[low];
                nums[low] = nums[mid];
                nums[mid] = tmp;
                ++low;
                ++mid;
                break;
            case 1:
                ++mid;
                break;
            case 2:
                tmp = nums[mid];
                nums[mid] = nums[high];
                nums[high] = tmp;
                --high;
                break;
        }
    }
#endif
}
