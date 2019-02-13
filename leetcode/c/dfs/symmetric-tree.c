/*
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following [1,2,2,null,3,null,3] is not:
    1
   / \
  2   2
   \   \
   3    3
Note:
Bonus points if you could solve it both recursively and iteratively.
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool
check_symmetric(struct TreeNode *left, struct TreeNode *right)
{
    /* if both are leaves, return true */
    if (!left && !right)
        return true;
    
    /* if only one is a leaf, return false */
    if (!left || !right)
        return false;
    
    /* if left val is same as right val, check the children */
    return ((left->val == right->val) &&
            check_symmetric(left->left, right->right) &&
            check_symmetric(left->right, right->left));    
}

bool isSymmetric(struct TreeNode* root) {
    if (!root)
        return true;
    return check_symmetric(root->left, root->right);    
}
