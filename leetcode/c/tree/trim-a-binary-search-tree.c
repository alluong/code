#if 0
669. Trim a Binary Search Tree
Easy

989

122

Favorite

Share
Given a binary search tree and the lowest and highest boundaries as L and R, trim the tree so that all its elements lies in [L, R] (R >= L). You might need to change the root of the tree, so the result should return the new root of the trimmed binary search tree.

Example 1:
Input: 
    1
   / \
  0   2

  L = 1
  R = 2

Output: 
    1
      \
       2
Example 2:
Input: 
    3
   / \
  0   4
   \
    2
   /
  1

  L = 1
  R = 3

Output: 
      3
     / 
   2   
  /
 1
Accepted
58,458
Submissions
97,882
#endif

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* trimBST(struct TreeNode* root, int L, int R) {
    if (!root)
        return NULL;

    /* trim left side */
    root->left = trimBST(root->left, L, R);

    /* trim right side */
    root->right = trimBST(root->right, L, R);
    if (root->val < L)
        return root->right;
    if (root->val > R)
        return root->left;
    return root;        
}
