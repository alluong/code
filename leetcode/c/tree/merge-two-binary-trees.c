/*
Given two binary trees and imagine that when you put one of them to cover the other, some nodes of the two trees are overlapped while the others are not.

You need to merge them into a new binary tree. The merge rule is that if two nodes overlap, then sum node values up as the new value of the merged node. Otherwise, the NOT null node will be used as the node of new tree.

Example 1:

Input: 
	Tree 1                     Tree 2                  
          1                         2                             
         / \                       / \                            
        3   2                     1   3                        
       /                           \   \                      
      5                             4   7                  
Output: 
Merged tree:
	     3
	    / \
	   4   5
	  / \   \ 
	 5   4   7
 

Note: The merging process must start from the root nodes of both trees.
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode *
new_node(int val)
{
    struct TreeNode *new = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    
    new->val = val;
    new->left = new->right = NULL;
    return new;
}

struct TreeNode* mergeTrees(struct TreeNode* t1, struct TreeNode* t2) {
    struct TreeNode *node, *root = NULL;
    int val;
    
    // empty tree
    if (!t1 && !t2)
        return NULL;
    val = 0;
    if (t1)
        val += t1->val;
    if (t2)
        val += t2->val;
    root = new_node(val);
    root->left = mergeTrees(t1 ? t1->left : NULL, t2 ? t2->left : NULL);
    root->right = mergeTrees(t1 ? t1->right : NULL, t2 ? t2->right : NULL);
    return root;
}
