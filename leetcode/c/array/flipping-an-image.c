#if 0
832. Flipping an Image
Easy

421

83

Favorite

Share
Given a binary matrix A, we want to flip the image horizontally, then invert it, and return the resulting image.

To flip an image horizontally means that each row of the image is reversed.  For example, flipping [1, 1, 0] horizontally results in [0, 1, 1].

To invert an image means that each 0 is replaced by 1, and each 1 is replaced by 0. For example, inverting [0, 1, 1] results in [1, 0, 0].

Example 1:

Input: [[1,1,0],[1,0,1],[0,0,0]]
Output: [[1,0,0],[0,1,0],[1,1,1]]
Explanation: First reverse each row: [[0,1,1],[1,0,1],[0,0,0]].
Then, invert the image: [[1,0,0],[0,1,0],[1,1,1]]
Example 2:

Input: [[1,1,0,0],[1,0,0,1],[0,1,1,1],[1,0,1,0]]
Output: [[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]]
Explanation: First reverse each row: [[0,0,1,1],[1,0,0,1],[1,1,1,0],[0,1,0,1]].
Then invert the image: [[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]]
Notes:

1 <= A.length = A[0].length <= 20
0 <= A[i][j] <= 1
Accepted
73,863
Submissions
103,528
#endif

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** flipAndInvertImage(int** A, int ARowSize, int *AColSizes, int** columnSizes, int* returnSize) {
    int row, col;
    int **arr;
    
    *returnSize = ARowSize;
    
    /* allocate array of pointers */
    arr = (int **)malloc(sizeof(int *) * ARowSize);
    
    /* allocate array of int */
    *columnSizes = (int *)malloc(sizeof(int) * ARowSize);
    for (row = 0; row < ARowSize; row++) {
        int *one_row;
                
        /* allocate memory for the row */
        one_row = (int *)malloc(sizeof(int) * (*AColSizes));
        for (col = 0; col < *AColSizes; col++) {
            one_row[*AColSizes - col - 1] =
                A[row][col] ^ 1;
        }
        arr[row] = one_row;
        (*columnSizes)[row] = *AColSizes;
    }
    return arr;
}
