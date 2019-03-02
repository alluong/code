#if 0
637. Average of Levels in Binary Tree
Easy

751

118

Favorite

Share
Given a non-empty binary tree, return the average value of the nodes on each level in the form of an array.
Example 1:
Input:
    3
   / \
  9  20
    /  \
   15   7
Output: [3, 14.5, 11]
Explanation:
The average value of nodes on level 0 is 3,  on level 1 is 14.5, and on level 2 is 11. Hence return [3, 14.5, 11].
Note:
The range of node's value is in the range of 32-bit signed integer.
Accepted
70,835
Submissions
122,193
#endif

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int get_tree_height(struct TreeNode *root)
{
    int left, right;
    
    if (!root)
        return 0;
    left = get_tree_height(root->left) + 1;
    right = get_tree_height(root->right) + 1;
    return (left > right) ? left : right;
}

void
level_order_traverse(struct TreeNode *root, int level, double *total, int *num_node)
{
    if (!root)
        return;
    if (level == 0) {
        *num_node += 1;
        *total += root->val;
    } else if (level > 0) {
        level_order_traverse(root->left, level - 1, total, num_node);
        level_order_traverse(root->right, level - 1, total, num_node);
    }
}

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
double* averageOfLevels(struct TreeNode* root, int* returnSize) {
    int height, ii, *num_node;
    double *total;
    
    /* get height of tree */
    height = get_tree_height(root);
    total = (double *)malloc(sizeof(double) * height);
    num_node = (int *)malloc(sizeof(int) * height);
    *returnSize = height;
    
    /* do level order traversal */
    for (ii = 0; ii < height; ii++) {
        total[ii] = 0;
        num_node[ii] = 0;
        
        /* accumulate the total and number of nodes using level order traversal */
        level_order_traverse(root, ii, total + ii, num_node + ii);
        
        /* divide to get average */
        total[ii] /= num_node[ii];
    }
    return total;
}
