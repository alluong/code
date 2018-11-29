/*
Invert a binary tree.

Example:

Input:

     4
   /   \
  2     7
 / \   / \
1   3 6   9
Output:

     4
   /   \
  7     2
 / \   / \
9   6 3   1
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* invertTree(struct TreeNode* root) {
    struct TreeNode *left, *right;

    if (!root)
        return NULL;
    if (root->left) {        
        left = invertTree(root->left);
    } else {
        left = NULL;
    }
    if (root->right) {
        right = invertTree(root->right);
    } else {
        right = NULL;
    }
    root->left = right;
    root->right = left;
    return root;
}
