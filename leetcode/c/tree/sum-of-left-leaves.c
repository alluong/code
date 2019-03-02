#if 0
404. Sum of Left Leaves
Easy

586

63

Favorite

Share
Find the sum of all left leaves in a given binary tree.

Example:

    3
   / \
  9  20
    /  \
   15   7

There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.
Accepted
116,310
Submissions
238,827
#endif

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void
get_sum(struct TreeNode *root, int *sum)
{
    if (!root)
        return;
    if (root && root->left && !root->left->left && !root->left->right)
        *sum += root->left->val;
    get_sum(root->left, sum);
    get_sum(root->right, sum);
}

int sumOfLeftLeaves(struct TreeNode* root) {
    int sum;

    sum = 0;
    get_sum(root, &sum);
    return sum;
}
