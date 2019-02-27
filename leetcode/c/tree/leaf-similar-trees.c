#if 0
872. Leaf-Similar Trees
Easy

320

18

Favorite

Share
Consider all the leaves of a binary tree.  From left to right order, the values of those leaves form a leaf value sequence.



For example, in the given tree above, the leaf value sequence is (6, 7, 4, 9, 8).

Two binary trees are considered leaf-similar if their leaf value sequence is the same.

Return true if and only if the two given trees with head nodes root1 and root2 are leaf-similar.

 

Note:

Both of the given trees will have between 1 and 100 nodes.
Accepted
34,787
Submissions
55,977
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
get_leaf(struct TreeNode *root, int *leaf, int *count)
{
    if (!root)
        return;
    get_leaf(root->left, leaf, count);
    if (!root->left && !root->right) {
        leaf[*count] = root->val;
        *leaf = root->val;
        (*count)++;
    }
    get_leaf(root->right, leaf, count);
}

bool leafSimilar(struct TreeNode* root1, struct TreeNode* root2) {
    int leaf1[100], leaf2[100];
    int count = 0;
    
    memset(leaf1, 0, sizeof(int) * 100);
    memset(leaf2, 0, sizeof(int) * 100);
    get_leaf(root1, leaf1, &count);
    count = 0;
    get_leaf(root2, leaf2, &count);
    if (memcmp(leaf1, leaf2, sizeof(int)  * 100) == 0)
        return true;
    return false;
}
