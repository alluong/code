#if 0
897. Increasing Order Search Tree
Easy

196

222

Favorite

Share
Given a tree, rearrange the tree in in-order so that the leftmost node in the tree is now the root of the tree, and every node has no left child and only 1 right child.

Example 1:
Input: [5,3,6,2,4,null,8,1,null,null,null,7,9]

       5
      / \
    3    6
   / \    \
  2   4    8
 /        / \ 
1        7   9

Output: [1,null,2,null,3,null,4,null,5,null,6,null,7,null,8,null,9]

 1
  \
   2
    \
     3
      \
       4
        \
         5
          \
           6
            \
             7
              \
               8
                \
                 9  
Note:

The number of nodes in the given tree will be between 1 and 100.
Each node will have a unique integer value from 0 to 1000.
Accepted
21,730
Submissions
34,596
#endif

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* increasingBST(struct TreeNode* root) {
    struct TreeNode *cur, *p, *tmp, *head, dummy;
    
    dummy.left = dummy.right = NULL;
    head = &dummy;
    cur = root;
    while (cur) {
        while (cur->left) {
            /*
             * go to the rightmost node of left subtree, which is the biggest
             * node of the left subtree
             */
            for (p = cur->left; p->right; p = p->right)
                ;
            
            /* connect the right most node to point to root */
            p->right = cur;
            tmp = cur->left;
            cur->left = NULL;
            cur = tmp;
        }
        head->right = cur;  /* cur is cur->left of the outer while loop */
        head = cur;
        cur = cur->right; /* repeat */
    }
    return dummy.right;
}
