#if 0
515. Find Largest Value in Each Tree Row
Medium

449

40

Favorite

Share
You need to find the largest value in each row of a binary tree.

Example:
Input: 

          1
         / \
        3   2
       / \   \  
      5   3   9 

Output: [1, 3, 9]
Accepted
58,390
Submissions
102,034
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
get_height(struct TreeNode *root)
{
    int left, right;
    
    if (!root)
        return 0;
    left = get_height(root->left) + 1;
    right = get_height(root->right) + 1;
    return left > right ? left : right;
}

void
level_order(struct TreeNode *root, int *arr, int level)
{
    if (!root)
        return;
    if (level == 0) {
        printf("root %d arr %d\n", root->val, *arr);
        if (root->val > *arr) {
            printf("in here\n");
            *arr = root->val;
        }
    }
    
    /* traverse down and decrement the level */
    level_order(root->left, arr, level - 1);
    level_order(root->right, arr, level - 1);      
}

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* largestValues(struct TreeNode* root, int* returnSize) {
    int height, *arr, level;
    
    height = get_height(root);
    *returnSize = height;
    if (height <= 0)
        return NULL;
    arr = (int *)malloc(sizeof(int) * height);
#if 0
    /* somehow memset is not working for leetcode */
    memset(arr, INT_MIN, sizeof(arr[0]) * height);
#else
    for (level = 0; level < height; level++) {
        arr[level] = INT_MIN;
    }
#endif
    for (level = 0; level < height; level++)   
        /* call level order and pass the arr address of that level */
        level_order(root, &arr[level], level);
    return arr;
}
