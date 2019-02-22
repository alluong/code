#if 0
905. Sort Array By Parity
Easy

355

45

Favorite

Share
Given an array A of non-negative integers, return an array consisting of all the even elements of A, followed by all the odd elements of A.

You may return any answer array that satisfies this condition.

 

Example 1:

Input: [3,1,2,4]
Output: [2,4,3,1]
The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be accepted.
 

Note:

1 <= A.length <= 5000
0 <= A[i] <= 5000
Accepted
65,327
Submissions
90,606
#endif

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArrayByParity(int* A, int ASize, int* returnSize) {
    int ii, last, tmp;
    
    last = ASize - 1;
    for (ii = 0; ii < last; ii++) {
        if (A[ii] % 2 != 0) {
            /* find odd element starting from the end */
            while (last > ii) {
                if (A[last] % 2 != 0)
                    --last;
                else
                    break;
            }
            tmp = A[ii];
            A[ii] = A[last];
            A[last] = tmp;
        }
    }
    *returnSize = ASize;
    return A;
}
