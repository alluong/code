#if 0
653. Two Sum IV - Input is a BST
Easy

782

93

Favorite

Share
Given a Binary Search Tree and a target number, return true if there exist two elements in the BST such that their sum is equal to the given target.

Example 1:

Input: 
    5
   / \
  3   6
 / \   \
2   4   7

Target = 9

Output: True
 

Example 2:

Input: 
    5
   / \
  3   6
 / \   \
2   4   7

Target = 28

Output: False
 

Accepted
75,644
Submissions
146,033
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
get_num_nodes(struct TreeNode *root)
{
    if (!root)
        return 0;
    return 1 +  get_num_nodes(root->left) + get_num_nodes(root->right);
}

void
in_order(struct TreeNode *root, int *arr, int *index)
{
    if (!root)
        return;
    in_order(root->left, arr, index);
    arr[*index] = root->val;
    *index += 1;
    in_order(root->right, arr, index);
}

bool findTarget(struct TreeNode* root, int k) {
    int num_nodes, *arr, index, ii, first, last;
    
    num_nodes = get_num_nodes(root);
    if (num_nodes < 2)
        return false;
    arr = (int *)malloc(sizeof(int) * num_nodes);
    index = 0;
    in_order(root, arr, &index);
    first = 0;
    last = num_nodes - 1;
    while (first < last) {
        if (arr[first] + arr[last] == k)
            return true;
        if (arr[first] + arr[last] < k)
            ++first;
        else
            --last;
    }
    return false;
}
