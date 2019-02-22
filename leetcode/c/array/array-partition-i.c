#if 0
561. Array Partition I
Easy

521

1526

Favorite

Share
Given an array of 2n integers, your task is to group these integers into n pairs of integer, say (a1, b1), (a2, b2), ..., (an, bn) which makes sum of min(ai, bi) for all i from 1 to n as large as possible.

Example 1:
Input: [1,4,3,2]

Output: 4
Explanation: n is 2, and the maximum sum of pairs is 4 = min(1, 2) + min(3, 4).
Note:
n is a positive integer, which is in the range of [1, 10000].
All the integers in the array will be in the range of [-10000, 10000].
Accepted
129,287
Submissions
189,460
#endif

void
swap(int *a, int *b)
{
    int tmp = *a;

    //printf("swap %d %d\n", a, b);
    *a = *b;
    *b = tmp;
}

int
partition(int *arr, int left, int right) {
    int pivot = arr[left];  /* choose first element to be pivot */
    int ii, jj, tmp;
    
    ii = left + 1;
    for (jj = left + 1; jj <= right; jj++) {
        if (arr[jj] < pivot) {
            swap(&arr[ii], &arr[jj]);
            ii++;
        }        
    }
    
    /* swap pivot element into its proper position */
    swap(&arr[left], &arr[ii - 1]);
    
    /* return pivot */
    return ii - 1;
}

void
quick_sort(int *arr, int left, int right) {
    if (left < right) {
        int pivot = partition(arr, left, right);
        
        /* sort elements left of pivot */
        quick_sort(arr, left, pivot - 1);
        
        /* sort elements right of pivot */
        quick_sort(arr, pivot + 1, right);
    }
}

int arrayPairSum(int* nums, int numsSize) {
    int sum, ii;
    
    sum = 0;
    quick_sort(nums, 0, numsSize - 1);
    for (ii = 0; ii < numsSize; ii += 2) {
        sum += nums[ii];
    }
    return sum;
}
