#if 0
111. Minimum Depth of Binary Tree
Easy

639

319

Favorite

Share
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

Note: A leaf is a node with no children.

Example:

Given binary tree [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
return its minimum depth = 2.
#endif

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#define min(a, b) ((a < b) ? a : b)

int minDepth(struct TreeNode* root) {
    // root is NULL, return 0
    if (!root)
        return 0;
    
    // it is a leaf, return 1
    if (!root->left && !root->right)
        return 1;
    
    // left node is NULL, do right
    if (!root->left)
        return minDepth(root->right) + 1;
    
    // right node is NULL, do left
    if (!root->right)
        return minDepth(root->left) + 1;
    
    // return minimum of left or right node
    return min(minDepth(root->left), minDepth(root->right)) + 1;
}
