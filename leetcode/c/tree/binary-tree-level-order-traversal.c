#if 0
102. Binary Tree Level Order Traversal
Medium

1232

32

Favorite

Share
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]
Accepted
337,014
Submissions
716,854
#endif

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
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

int** levelOrder(struct TreeNode* root, int** columnSizes, int* returnSize) {
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
        
        /* set column size for that level and array to point to one_row */
        (*columnSizes)[level] = count;
        arr[level] = one_row;
    }
    return arr;
}
