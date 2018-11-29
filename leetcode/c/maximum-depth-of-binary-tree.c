/*
Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

Note: A leaf is a node with no children.

Example:

Given binary tree [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
return its depth = 3.
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#define max(a, b) ((a > b) ? a : b)

int maxDepth(struct TreeNode* root) {
    int left, right;
    
    // root is NULL, return 0
    if (!root)
        return 0;
    left = maxDepth(root->left);
    right = maxDepth(root->right);
    
    // return maximum of left or right node
    return max(left, right) + 1;  
}
