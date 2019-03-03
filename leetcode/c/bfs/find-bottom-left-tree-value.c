#if 0
513. Find Bottom Left Tree Value
Medium

514

85

Favorite

Share
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
65,612
Submissions
113,346
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
    return left > right ? left : right;
}

void
level_order(struct TreeNode *root, int *val, int level)
{
    if (!root)
        return;
    if (level == 0) {
        /* set first value */
        if (*val == INT_MAX)
            *val = root->val;
    }
    
    /* traverse down and decrement the level */
    level_order(root->left, val, level - 1);
    level_order(root->right, val, level - 1);      
}

int findBottomLeftValue(struct TreeNode* root) {
    int height, val = INT_MAX;
    
    height = get_height(root);
    if (height <= 0)
        return 0;

    /* call level order and pass the arr address of that level */
    level_order(root, &val, height - 1);
    return val;
}
