#if 0
661. Image Smoother
Easy

165

718

Favorite

Share
Given a 2D integer matrix M representing the gray scale of an image, you need to design a smoother to make the gray scale of each cell becomes the average gray scale (rounding down) of all the 8 surrounding cells and itself. If a cell has less than 8 surrounding cells, then use as many as you can.

Example 1:
Input:
[[1,1,1],
 [1,0,1],
 [1,1,1]]
Output:
[[0, 0, 0],
 [0, 0, 0],
 [0, 0, 0]]
Explanation:
For the point (0,0), (0,2), (2,0), (2,2): floor(3/4) = floor(0.75) = 0
For the point (0,1), (1,0), (1,2), (2,1): floor(5/6) = floor(0.83333333) = 0
For the point (1,1): floor(8/9) = floor(0.88888889) = 0
Note:
The value in the given matrix is in the range of [0, 255].
The length and width of the given matrix are in the range of [1, 150].
Accepted
31,130
Submissions
65,033
#endif

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** imageSmoother(int** M, int MRowSize, int MColSize, int** columnSizes, int* returnSize) {
    int **arr, row, col, ii, jj, num_cell, sum;
    
    arr = (int **)malloc(sizeof(int *) * MRowSize);
    *returnSize = MRowSize;
    if (!MRowSize || !MColSize) {
        *columnSizes = (int *)malloc(sizeof(int) * (MRowSize + 1));
        (*columnSizes)[0] = 0;
        return arr;
    }
    *columnSizes = (int *)malloc(sizeof(int) * MRowSize);
    for (row = 0; row < MRowSize; row++) {
        int *one_row = (int *)malloc(sizeof(int) * MColSize);
    
        for (col = 0; col < MColSize; col++) {
            num_cell = 0;
            sum = 0;
            for (ii = row - 1; ii <= row + 1; ii++) {
                for (jj = col - 1; jj <= col + 1; jj++) {
                    if (ii < 0 || ii >= MRowSize || jj < 0 || jj >= MColSize)
                        continue;
                    sum += M[ii][jj];
                    ++num_cell;
                }     
            }
            one_row[col] = sum / num_cell;
        }
        (*columnSizes)[row] = MColSize;
        arr[row] = one_row;
    }
    return arr;
}
