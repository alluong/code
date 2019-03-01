#if 0
112. Path Sum
Easy

796

254

Favorite

Share
Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

Note: A leaf is a node with no children.

Example:

Given the below binary tree and sum = 22,

      5
     / \
    4   8
   /   / \
  11  13  4
 /  \      \
7    2      1
return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
#endif

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool hasPathSum(struct TreeNode* root, int sum) {
    if (!root) {
        return false;
    }
    
    // leaf node
    if (!root->left && !root->right) {
        if (root->val == sum)
            return true;
    }
    
    // left subtree
    if (root->left) {
        if (hasPathSum(root->left, sum - root->val))
            return true;
    }
    
    // right subtree
    if (root->right) {
        if (hasPathSum(root->right, sum - root->val))
            return true;
    }
    return false;
}
