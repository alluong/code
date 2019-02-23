#if 0
566. Reshape the Matrix
Easy

513

77

Favorite

Share
In MATLAB, there is a very useful function called 'reshape', which can reshape a matrix into a new one with different size but keep its original data.

You're given a matrix represented by a two-dimensional array, and two positive integers r and c representing the row number and column number of the wanted reshaped matrix, respectively.

The reshaped matrix need to be filled with all the elements of the original matrix in the same row-traversing order as they were.

If the 'reshape' operation with given parameters is possible and legal, output the new reshaped matrix; Otherwise, output the original matrix.

Example 1:
Input: 
nums = 
[[1,2],
 [3,4]]
r = 1, c = 4
Output: 
[[1,2,3,4]]
Explanation:
The row-traversing of nums is [1,2,3,4]. The new reshaped matrix is a 1 * 4 matrix, fill it row by row by using the previous list.
Example 2:
Input: 
nums = 
[[1,2],
 [3,4]]
r = 2, c = 4
Output: 
[[1,2],
 [3,4]]
Explanation:
There is no way to reshape a 2 * 2 matrix to a 2 * 4 matrix. So output the original matrix.
Note:
The height and width of the given matrix is in range [1, 100].
The given r and c are all positive.
Accepted
71,179
Submissions
121,909
#endif

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** matrixReshape(int** nums, int numsRowSize, int numsColSize, int r, int c, int** columnSizes, int* returnSize) {
    int **arr;
    int row, col, r_org, c_org;

    if (r * c != numsRowSize * numsColSize) {
        *returnSize = numsRowSize;
        *columnSizes = (int *)malloc(sizeof(int) * numsRowSize);
        for (row = 0; row < numsRowSize; row++)
            (*columnSizes)[row] = numsColSize;
        return nums;
    }
    *returnSize = r;
    arr = (int **)malloc(sizeof(int *) * r);
    *columnSizes = (int *)malloc(sizeof(int) * r);
    r_org = c_org = 0;
    for (row = 0; row < r; row++) {
        int *one_row = (int *)malloc(sizeof(int) * c);
    
        for (col = 0; col < c; col++) {
            one_row[col] = nums[r_org][c_org];
            ++c_org;
            if (c_org >= numsColSize) {
                c_org = 0;
                ++r_org;
            }
        }
        (*columnSizes)[row] = c;
        arr[row] = one_row;
    }
    return arr;
}

