#if 0
965. Univalued Binary Tree
Easy

108

20

Favorite

Share
A binary tree is univalued if every node in the tree has the same value.

Return true if and only if the given tree is univalued.

 

Example 1:


Input: [1,1,1,1,1,null,1]
Output: true
Example 2:


Input: [2,2,2,5,2]
Output: false
 

Note:

The number of nodes in the given tree will be in the range [1, 100].
Each node's value will be an integer in the range [0, 99].
Accepted
19,606
Submissions
28,937
#endif

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool
check_unival_tree(struct TreeNode *node, int val)
{
    if (!node)
        return true;
    if (node->val != val)
        return false;
    return (check_unival_tree(node->left, val) &&
            check_unival_tree(node->right, val));
}

bool isUnivalTree(struct TreeNode* root) {
    int val;
    
    if (!root)
        return true;
    val = root->val;
    return check_unival_tree(root, val);
}
