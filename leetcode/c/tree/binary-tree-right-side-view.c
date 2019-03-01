#if 0
199. Binary Tree Right Side View
Medium

867

35

Favorite

Share
Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

Example:

Input: [1,2,3,null,5,null,4]
Output: [1, 3, 4]
Explanation:

   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---
Accepted
150,896
Submissions
324,092
#endif

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

/* get height of tree */
int
tree_height(struct TreeNode *root)
{
    int lh, rh;

    if (!root)
        return 0;
    lh = tree_height(root->left) + 1;
    rh = tree_height(root->right) + 1;
    return (lh > rh) ? lh : rh;
}

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
void
level_one_traversal(struct TreeNode *root, int level, int arr[], int cur_level)
{
    if (!root)
        return;
    if (level == 1) {
        arr[cur_level] = root->val;
    } else if (level > 1) {
        level_one_traversal(root->left, level - 1, arr, cur_level);
        level_one_traversal(root->right, level - 1, arr, cur_level);
    }
    return;
}

int *
level_order_traversal(struct TreeNode *root, int *returnSize)
{
    int height, ii, *arr = NULL;
    
    if (!root) {
        *returnSize = 0;
        return NULL;
    }
    height = tree_height(root);
    *returnSize = height;
    arr = (int *)malloc(sizeof(int) * height);
    for (ii = 1; ii <= height; ii++) {
        level_one_traversal(root, ii, arr, ii - 1);
    }
    return arr;
}

int* rightSideView(struct TreeNode* root, int* returnSize) {
    int *result;
    
    // do a level order traversal, the last node will be the one on each level
    result = level_order_traversal(root, returnSize);
    return result;
}
