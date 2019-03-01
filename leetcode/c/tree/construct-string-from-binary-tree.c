#if 0
606. Construct String from Binary Tree
Easy

491

669

Favorite

Share
You need to construct a string consists of parenthesis and integers from a binary tree with the preorder traversing way.

The null node needs to be represented by empty parenthesis pair "()". And you need to omit all the empty parenthesis pairs that don't affect the one-to-one mapping relationship between the string and the original binary tree.

Example 1:
Input: Binary tree: [1,2,3,4]
       1
     /   \
    2     3
   /    
  4     

Output: "1(2(4))(3)"

Explanation: Originallay it needs to be "1(2(4)())(3()())", 
but you need to omit all the unnecessary empty parenthesis pairs. 
And it will be "1(2(4))(3)".
Example 2:
Input: Binary tree: [1,2,3,null,4]
       1
     /   \
    2     3
     \  
      4 

Output: "1(2()(4))(3)"

Explanation: Almost the same as the first example, 
except we can't omit the first parenthesis pair to break the one-to-one mapping relationship between the input and the output.
Accepted
53,208
Submissions
104,251
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
get_tree_height(struct TreeNode *root)
{
    int left, right;
    
    if (!root)
        return 0;
    left = get_tree_height(root->left) + 1;
    right = get_tree_height(root->right) + 1;
    return (left > right) ? left : right;
}

void
pre_order(struct TreeNode *root,  char *arr, int *len)
{
    int size;
    
    if (!root)
        return;
    
    /* print the node value */
    size = sprintf(arr + *len, "%d", root->val);
    *len += size;
    if (!root->left && !root->right)
        /* done */
        return;

    /* left node */
    size = sprintf(arr + *len, "(");    
    *len += size;
    pre_order(root->left, arr, len);
    size = sprintf(arr + *len, ")");    
    *len += size;
    
    /* right node */
    if (root->right) {
        size = sprintf(arr + *len, "(");    
        *len += size;
        pre_order(root->right, arr, len);
        size = sprintf(arr + *len, ")");    
        *len += size;
    }
}

char* tree2str(struct TreeNode* t) {
    int len, height;
    char *arr;
    
    len = 0;
    height = get_tree_height(t);
    if (!height)
        return "";
    arr = (char *)malloc(sizeof(char) * 100000);
    memset(arr, 0, sizeof(char) * 100000);
    pre_order(t, arr, &len);
    return arr;
}
