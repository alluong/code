/*
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following [1,2,2,null,3,null,3] is not:
    1
   / \
  2   2
   \   \
   3    3
Note:
Bonus points if you could solve it both recursively and iteratively.
*/
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func check_symmetric(left *TreeNode, right *TreeNode) bool {
    // both leaves
    if left == nil && right == nil {
        return true
    }
    
    // only one is leaf
    if left == nil || right == nil {
        return false
    }
    
    // left == right, traverse
    return (left.Val == right.Val &&
            check_symmetric(left.Left, right.Right) &&
            check_symmetric(left.Right, right.Left));
}

func isSymmetric(root *TreeNode) bool {
    if root == nil {
        return true
    }
    return check_symmetric(root.Left, root.Right);
}
