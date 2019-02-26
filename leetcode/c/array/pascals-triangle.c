#if 0
118. Pascal's Triangle
Easy

607

71

Favorite

Share
Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.


In Pascal's triangle, each number is the sum of the two numbers directly above it.

Example:

Input: 5
Output:
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
Accepted
227,064
Submissions
510,706
#endif

/**
 * Return an array of arrays.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int** columnSizes) {
    int **arr, ii, jj;
    
    if (numRows <= 0)
        return NULL;
    arr = (int **)malloc(sizeof(int *) * numRows);
    *columnSizes = (int *)malloc(sizeof(int) * numRows);
    for (ii = 0; ii < numRows; ii++) {
        int *one_row = (int *)malloc(sizeof(int) * (ii + 1));
        
        for (jj = 0; jj < ii + 1; jj++) {
            if (jj == 0 || jj == ii)
                /* if first or last element of the row, set it to 1 */
                one_row[jj] = 1;
            else
                /* sum the 2 elements from the previous row */
                one_row[jj] = arr[ii - 1][jj - 1] + arr[ii - 1][jj];
        }
        (*columnSizes)[ii] = ii + 1;
        arr[ii] = one_row;
    }
    return arr;
}
