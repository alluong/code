#if 0
119. Pascal's Triangle II
Easy

412

152

Favorite

Share
Given a non-negative index k where k ≤ 33, return the kth index row of the Pascal's triangle.

Note that the row index starts from 0.


In Pascal's triangle, each number is the sum of the two numbers directly above it.

Example:

Input: 3
Output: [1,3,3,1]
Follow up:

Could you optimize your algorithm to use only O(k) extra space?

Accepted
184,208
Submissions
439,117
#endif

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getRow(int rowIndex, int* returnSize) {
    int ii, jj, *arr;
    
    if (rowIndex < 0)
        return NULL;
    *returnSize = rowIndex + 1;
    arr = (int *)malloc(sizeof(int) * (rowIndex + 1));
    for (ii = 0; ii < rowIndex + 1; ii++) {
        /* iterate jj from end  to avoid adding elements at the beginning before using */
        for (jj = ii; jj >= 0; jj--) {
            if (jj == 0 || jj == ii)
                arr[jj] = 1;
            else
                arr[jj] += arr[jj - 1];
        }
    }
    return arr;
}
