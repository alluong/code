#if 0
687. Longest Univalue Path
Easy

854

186

Favorite

Share
Given a binary tree, find the length of the longest path where each node in the path has the same value. This path may or may not pass through the root.

Note: The length of path between two nodes is represented by the number of edges between them.

Example 1:

Input:

              5
             / \
            4   5
           / \   \
          1   1   5
Output:

2
Example 2:

Input:

              1
             / \
            4   5
           / \   \
          4   4   5
Output:

2
Note: The given binary tree has not more than 10000 nodes. The height of the tree is not more than 1000.

Accepted
51,837
Submissions
155,397
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
get_longest_path(struct TreeNode *root, int *max)
{
    int left, right;
    
    if (!root)
        return 0;
    left = get_longest_path(root->left, max);
    right = get_longest_path(root->right, max);
    if (root->left && root->val == root->left->val)
        left++;
    else
        left = 0;
    if (root->right && root->val == root->right->val)
        right++;
    else 
        right = 0;
    
    /* capture the max value */
    *max = *max > (left + right) ? *max : (left + right);
    return left > right ? left : right;
}

int longestUnivaluePath(struct TreeNode* root) {
    int path = 0;

    get_longest_path(root, &path);
    return path;
}
