#if 0
993. Cousins in Binary Tree
Easy

64

4

Favorite

Share
In a binary tree, the root node is at depth 0, and children of each depth k node are at depth k+1.

Two nodes of a binary tree are cousins if they have the same depth, but have different parents.

We are given the root of a binary tree with unique values, and the values x and y of two different nodes in the tree.

Return true if and only if the nodes corresponding to the values x and y are cousins.

 

Example 1:


Input: root = [1,2,3,4], x = 4, y = 3
Output: false
Example 2:


Input: root = [1,2,3,null,4,null,5], x = 5, y = 4
Output: true
Example 3:



Input: root = [1,2,3,null,4], x = 2, y = 3
Output: false
 

Note:

The number of nodes in the tree will be between 2 and 100.
Each node has a unique integer value from 1 to 100.
 
Accepted
6,895
Submissions
12,838
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
get_level(struct TreeNode *root, struct TreeNode *prev,
          struct TreeNode **parent, int val, int *level, int cur)
{
    if (!root)
        return;
    if (root->val == val) {
        *level = cur;
        *parent = prev;
        return;
    }
    get_level(root->left, root, parent, val, level, cur + 1);
    get_level(root->right, root, parent, val, level, cur + 1);    
}

bool isCousins(struct TreeNode* root, int x, int y) {
    int level_x, level_y;
    struct TreeNode *px, *py;
    
    px = py = NULL;
    level_x = level_y = 0;
    get_level(root, NULL, &px, x, &level_x, 0);
    get_level(root, NULL, &py, y, &level_y, 0);
    
    /* they are cousin iff they have the same level and different parents */
    return (level_x == level_y && px != py);
}
