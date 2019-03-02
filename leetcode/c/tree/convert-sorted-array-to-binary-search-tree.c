#if 0
108. Convert Sorted Array to Binary Search Tree
Easy

970

99

Favorite

Share
Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

Example:

Given the sorted array: [-10,-3,0,5,9],

One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:

      0
     / \
   -3   9
   /   /
 -10  5
Accepted
238,164
Submissions
483,828
#endif

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode *
sorted_array_to_bst(int *arr, int start, int end)
{
    struct TreeNode *node = NULL;

    if (start <= end) {
        int mid = (start + end) / 2;
        
        /* got the middle, insert it */
        node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
        node->val = arr[mid];
        node->left = sorted_array_to_bst(arr, start, mid - 1);
        node->right = sorted_array_to_bst(arr, mid + 1, end);
    }
    return node;
}

struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    struct TreeNode *root;
    
    root = sorted_array_to_bst(nums, 0, numsSize - 1);
    return root;
}
