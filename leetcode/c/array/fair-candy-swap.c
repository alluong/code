#if 0
888. Fair Candy Swap
Easy

236

64

Favorite

Share
Alice and Bob have candy bars of different sizes: A[i] is the size of the i-th bar of candy that Alice has, and B[j] is the size of the j-th bar of candy that Bob has.

Since they are friends, they would like to exchange one candy bar each so that after the exchange, they both have the same total amount of candy.  (The total amount of candy a person has is the sum of the sizes of candy bars they have.)

Return an integer array ans where ans[0] is the size of the candy bar that Alice must exchange, and ans[1] is the size of the candy bar that Bob must exchange.

If there are multiple answers, you may return any one of them.  It is guaranteed an answer exists.

 

Example 1:

Input: A = [1,1], B = [2,2]
Output: [1,2]
Example 2:

Input: A = [1,2], B = [2,3]
Output: [1,2]
Example 3:

Input: A = [2], B = [1,3]
Output: [2,3]
Example 4:

Input: A = [1,2,5], B = [2,4]
Output: [5,4]
 

Note:

1 <= A.length <= 10000
1 <= B.length <= 10000
1 <= A[i] <= 100000
1 <= B[i] <= 100000
It is guaranteed that Alice and Bob have different total amounts of candy.
It is guaranteed there exists an answer.
Accepted
20,419
Submissions
36,681
#endif

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int cmpfunc (const void *a, const void *b)
{
   return (*(int *)a - *(int *)b);
}

int* fairCandySwap(int* A, int ASize, int* B, int BSize, int* returnSize) {
    int *ans = (int *)malloc(sizeof(int) * 2);
    int ii, jj, a_sum, b_sum, diff;
    
    *returnSize = 2;
    qsort(A, ASize, sizeof(A[0]), cmpfunc);
    qsort(B, BSize, sizeof(B[0]), cmpfunc);
    a_sum = 0;
    for (ii = 0; ii < ASize; ii++)
        a_sum += A[ii];
    b_sum = 0;
    for (ii = 0; ii < BSize; ii++)
        b_sum += B[ii];
    diff = a_sum - b_sum;
    for (ii = 0; ii < ASize; ii++) {
        for (jj = BSize - 1; jj >= 0; jj--) {
            if (2 * (A[ii] - B[jj]) == diff)
                goto _exit;
        }
    }
_exit:
    ans[0] = A[ii];
    ans[1] = B[jj];
    return ans;
}
