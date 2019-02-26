#if 0
830. Positions of Large Groups
Easy

173

42

Favorite

Share
In a string S of lowercase letters, these letters form consecutive groups of the same character.

For example, a string like S = "abbxxxxzyy" has the groups "a", "bb", "xxxx", "z" and "yy".

Call a group large if it has 3 or more characters.  We would like the starting and ending positions of every large group.

The final answer should be in lexicographic order.

 

Example 1:

Input: "abbxxxxzzy"
Output: [[3,6]]
Explanation: "xxxx" is the single large group with starting  3 and ending positions 6.
Example 2:

Input: "abc"
Output: []
Explanation: We have "a","b" and "c" but no large group.
Example 3:

Input: "abcdddeeeeaabbbcd"
Output: [[3,5],[6,9],[12,14]]
 

Note:  1 <= S.length <= 1000

Accepted
22,089
Submissions
46,615
#endif

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int
add_one_entry(int **arr, int **colSize, int row, int begin, int end)
{
    int *one_row = (int *)malloc(sizeof(int) * 2);

    one_row[0] = begin;
    one_row[1] = end;
    (*colSize)[row] = 2;
    arr[row] = one_row;
    return row + 1;
}

int** largeGroupPositions(char* S, int** columnSizes, int* returnSize) {
    char c;
    int count, begin, pos = 0, row;
    int **arr;

    *returnSize = 0;
    c = S[0];
    count = 1;
    begin = 0;
    S++;
    row = 0;
    arr = (int **)malloc(sizeof(int *) * 1000 / 3);
    *columnSizes = (int *)malloc(sizeof(int) * 1000 / 3);
    while (*S) {
        if (c == *S) {
            /* repeating char, bump count */
            ++count;
        } else {
            if (count >= 3) {
                row = add_one_entry(arr, columnSizes, row, begin, pos);
            }
            c = *S;
            count = 1;
            begin = pos + 1;
        }
        ++pos;
        ++S;
    }
    
    /* add last one as needed */
    if (count >= 3)
        row = add_one_entry(arr, columnSizes, row, begin, pos);
    *returnSize = row;
    return arr;
}
