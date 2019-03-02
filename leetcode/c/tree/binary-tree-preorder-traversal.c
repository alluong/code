#if 0
144. Binary Tree Preorder Traversal
Medium

653

35

Favorite

Share
Given a binary tree, return the preorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [1,2,3]
Follow up: Recursive solution is trivial, could you do it iteratively?

Accepted
305,691
Submissions
608,540
#endif

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
void
get_node_cnt(struct TreeNode *root, int *count)
{
    if (!root)
        return;
    (*count)++;
    get_node_cnt(root->left, count);
    get_node_cnt(root->right, count);
}

void
preorder(struct TreeNode *root, int *arr, int *index)
{
    if (!root)
        return;
    arr[*index] = root->val;
    *index += 1;
    preorder(root->left, arr, index);
    preorder(root->right, arr, index);
}

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    int node_cnt, *arr, index;
    
    node_cnt = 0;
    get_node_cnt(root, &node_cnt);
    *returnSize = node_cnt;
    if (node_cnt <= 0)
        return NULL;
    arr = (int *)malloc(sizeof(int) * node_cnt);
    index = 0;
    preorder(root, arr, &index);
    return arr;
}
