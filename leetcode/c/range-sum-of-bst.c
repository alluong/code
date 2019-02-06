#if 0
Given the root node of a binary search tree, return the sum of values of all nodes with value between L and R (inclusive).

The binary search tree is guaranteed to have unique values.

 

Example 1:

Input: root = [10,5,15,3,7,null,18], L = 7, R = 15
Output: 32
Example 2:

Input: root = [10,5,15,3,7,13,18,1,null,6], L = 6, R = 10
Output: 23
#endif

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int rangeSumBST(struct TreeNode* root, int L, int R) {
    int sum = 0;
    
    if (!root)
        return sum;
    if (root->val > L)
        sum += rangeSumBST(root->left, L, R);
    if (root->val < R)
        sum += rangeSumBST(root->right, L, R);
    if (root->val >= L && root->val <= R)
        sum += root->val;
    return sum;        
}

int rangeSumBST(struct TreeNode* root, int L, int R) {
    int sum = 0;
    
    if (!root)
        return sum;
    if (root->val >= L && root->val <= R)
        sum = root->val;
    return sum + rangeSumBST(root->left, L, R) + rangeSumBST(root->right, L, R);
}
