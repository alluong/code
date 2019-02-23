#if 0
867. Transpose Matrix
Easy

164

176

Favorite

Share
Given a matrix A, return the transpose of A.

The transpose of a matrix is the matrix flipped over it's main diagonal, switching the row and column indices of the matrix.

 

Example 1:

Input: [[1,2,3],[4,5,6],[7,8,9]]
Output: [[1,4,7],[2,5,8],[3,6,9]]
Example 2:

Input: [[1,2,3],[4,5,6]]
Output: [[1,4],[2,5],[3,6]]
 

Note:

1 <= A.length <= 1000
1 <= A[0].length <= 1000
Accepted
37,053
Submissions
58,214
#endif

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** transpose(int** A, int ARowSize, int *AColSize, int** columnSizes, int* returnSize) {
    int **arr;
    int row, col;
    
    /* returnSize is AColSize because we are transposing the matrix */
    *returnSize = *AColSize;
    
    /* allocate memories */
    arr = (int **)malloc(sizeof(int *) * (*AColSize));
    *columnSizes = (int *)malloc(sizeof(int *) * (*AColSize));
    
    /* need to start with col iteration first due to transpose */
    for (col = 0; col < *AColSize; col++) {
        int *one_row = (int *)malloc(sizeof(int) * ARowSize);
    
        for (row = 0; row < ARowSize; row++) {
            one_row[row] = A[row][col];
        }
        arr[col] = one_row;
        (*columnSizes)[col] = ARowSize;
    }
    return arr;    
}
