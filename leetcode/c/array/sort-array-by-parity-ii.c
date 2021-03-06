#if 0
922. Sort Array By Parity II
Easy

197

20

Favorite

Share
Given an array A of non-negative integers, half of the integers in A are odd, and half of the integers are even.

Sort the array so that whenever A[i] is odd, i is odd; and whenever A[i] is even, i is even.

You may return any answer array that satisfies this condition.

 

Example 1:

Input: [4,2,5,7]
Output: [4,5,2,7]
Explanation: [4,7,2,5], [2,5,4,7], [2,7,4,5] would also have been accepted.
 

Note:

2 <= A.length <= 20000
A.length % 2 == 0
0 <= A[i] <= 1000
 

Accepted
28,576
Submissions
42,870
#endif

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArrayByParityII(int* A, int ASize, int* returnSize) {
    int ii, *arr, odd, even;

    odd = 1;
    even = 0;
    arr = (int *)malloc(sizeof(int) * ASize);
    *returnSize = ASize;
    for (ii = 0; ii < ASize; ii++) {
        if (A[ii] % 2 == 0) {
            arr[even] = A[ii];
            even += 2;
        } else {
            arr[odd] = A[ii];
            odd += 2;
        }
    }
    return arr;
}
