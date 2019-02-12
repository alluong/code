#if 0
Given an array of integers A sorted in non-decreasing order, return an array of the squares of each number, also in sorted non-decreasing order.

 

Example 1:

Input: [-4,-1,0,3,10]
Output: [0,1,9,16,100]
Example 2:

Input: [-7,-3,2,3,11]
Output: [4,9,9,49,121]
 

Note:

1 <= A.length <= 10000
-10000 <= A[i] <= 10000
A is sorted in non-decreasing order.
#endif

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int
cmpfunc(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int* sortedSquares(int* A, int ASize, int* returnSize) {
    int *arr = malloc(sizeof(int) * ASize), ii;
    
    for (ii = 0; ii < ASize; ii++) {
        arr[ii] = A[ii] * A[ii];
    }
    *returnSize = ASize;
    qsort(arr, ASize, sizeof(int), cmpfunc);
    return arr;
}
