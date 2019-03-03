#if 0
Given a binary tree, find the leftmost value in the last row of the tree.

Example 1:
Input:

    2
   / \
  1   3

Output:
1
Example 2: 
Input:

        1
       / \
      2   3
     /   / \
    4   5   6
       /
      7

Output:
7
Note: You may assume the tree (i.e., the given root node) is not NULL.

Accepted
65,608
Submissions
113,341
#endif

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int
get_height(struct TreeNode *root)
{
    int left, right;
    if (!root)
        return 0;
    left = get_height(root->left) + 1;
    right = get_height(root->right) + 1;
    return (left > right) ? left : right;
}

void
level_order(struct TreeNode *root, int level, int *arr, int *index)
{
    /* be sure to check for null */
    if (!root)
        return;
    if (level == 0) {
        arr[*index] = root->val;
        *index += 1;
        return;
    }
    level_order(root->left, level - 1, arr, index);
    level_order(root->right, level - 1, arr, index);
}

void
reverse(int **arr, int *col_size, int level)
{
    int *tmp, size, start;
    
    start = 0;
    while (start < level - 1) {
        tmp = arr[start];
        arr[start] = arr[level - 1];
        arr[level - 1] = tmp;
        size = col_size[start];
        col_size[start] = col_size[level - 1];
        col_size[level - 1] = size;
        ++start;
        --level;
    }
}
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** levelOrderBottom(struct TreeNode* root, int** columnSizes, int* returnSize) {
    int **arr, height, level;
    
    height = get_height(root);
    *returnSize = height;
    if (height <= 0) {
        return NULL;
    }
    
    /* allocate array of pointers for tree height and column size for each row */
    arr = (int **)malloc(sizeof(int *) * height);
    *columnSizes = (int *)malloc(sizeof(int) * height);
    for (level = 0; level < height; level++) {
        int count = 0;
        int *one_row = (int *)malloc(sizeof(int) * 1024); /* assuming max 1024 leaves */
        
        level_order(root, level, one_row, &count);

#if 1 /* no need to call reverse in this case */
        /* set column size for that level and array to point to one_row */
        (*columnSizes)[height - level - 1] = count;
        arr[height - level - 1] = one_row;
#else
        /* set column size for that level and array to point to one_row */
        (*columnSizes)[level] = count;
        arr[level] = one_row;
#endif
    }
//    reverse(arr, *columnSizes, height);
    return arr;
}
