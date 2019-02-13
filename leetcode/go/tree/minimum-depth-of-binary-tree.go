/*
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

Note: A leaf is a node with no children.

Example:

Given binary tree [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
return its minimum depth = 2.
*/
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func minDepth(root *TreeNode) int {    
    // root is nil, return 0
    if root == nil {
        return 0
    }
    
    // leaf, return 1
    if root.Left == nil && root.Right == nil {
        return 1
    }
    
    // left is nil, traverse right
    if root.Left == nil {
        return minDepth(root.Right) + 1;
    }
    
    // right is nil, traverse left
    if root.Right == nil {
        return minDepth(root.Left) + 1;
    }
    left := minDepth(root.Left);
    right := minDepth(root.Right);  
    if left < right {
        return left + 1
    }
    return right + 1
}
