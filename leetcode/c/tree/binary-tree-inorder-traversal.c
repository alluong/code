#if 0
94. Binary Tree Inorder Traversal
Medium

1371

59

Favorite

Share
Given a binary tree, return the inorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [1,3,2]
Follow up: Recursive solution is trivial, could you do it iteratively?

Accepted
410,563
Submissions
746,052
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
get_node_cnt(struct TreeNode *root, int *count)
{
    if (!root)
        return;
    (*count)++;
    get_node_cnt(root->left, count);
    get_node_cnt(root->right, count);
}

void
inorder(struct TreeNode *root, int *arr, int *index)
{
    if (!root)
        return;
    inorder(root->left, arr, index);
    arr[*index] = root->val;
    *index += 1;
    inorder(root->right, arr, index);
}

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int node_cnt, *arr, index;
    
    node_cnt = 0;
    get_node_cnt(root, &node_cnt);
    *returnSize = node_cnt;
    if (node_cnt <= 0)
        return NULL;
    arr = (int *)malloc(sizeof(int) * node_cnt);
    index = 0;
    inorder(root, arr, &index);
    return arr;    
}
