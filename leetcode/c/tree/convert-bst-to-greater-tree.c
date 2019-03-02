#if 0
538. Convert BST to Greater Tree
Easy

1127

79

Favorite

Share
Given a Binary Search Tree (BST), convert it to a Greater Tree such that every key of the original BST is changed to the original key plus sum of all keys greater than the original key in BST.

Example:

Input: The root of a Binary Search Tree like this:
              5
            /   \
           2     13

Output: The root of a Greater Tree like this:
             18
            /   \
          20     13
Accepted
69,034
Submissions
138,272
#endif

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#if 1
struct TreeNode *
invert_tree(struct TreeNode* root)
{
    struct TreeNode *left, *right;

    if (!root)
        return NULL;
    if (root->left) {
        left = invert_tree(root->left);
    } else {
        left = NULL;
    }
    if (root->right) {
        right = invert_tree(root->right);
    } else {
        right = NULL;
    }
    root->left = right;
    root->right = left;
    return root;
}

void
in_order(struct TreeNode *root, int *val)
{
    if (!root)
        return;
    in_order(root->left, val);
    *val += root->val;
    root->val = *val;
    in_order(root->right, val);
}

struct TreeNode* convertBST(struct TreeNode* root) {
    int val = 0;
    
    /* invert the tree */
    root = invert_tree(root);
    
    /* do in order traversal and add up the nodes */
    in_order(root, &val);
    
    /* invert back */
    root = invert_tree(root);
    return root;
}

#else
int visit(struct TreeNode* root, int val)
{
    if (root == NULL)
        return val;
    root->val += visit(root->right, val);
    return visit(root->left, root->val);;   
}

struct TreeNode* convertBST(struct TreeNode* root) {
    visit(root, 0);
    return root;
}
#endif
