#if 0
109. Convert Sorted List to Binary Search Tree
Medium

821

61

Favorite

Share
Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

Example:

Given the sorted linked list: [-10,-3,0,5,9],

One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:

      0
     / \
   -3   9
   /   /
 -10  5
Accepted
163,048
Submissions
413,811
#endif

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void
print_list(struct ListNode *head)
{
    while (head) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}
struct TreeNode *sort_list_to_bst_helper(struct ListNode *head,
                                         struct ListNode *tail)
{
    struct ListNode *slow, *fast;
    struct TreeNode *node;
    
    if (head == tail)
        return NULL;
    slow = head;
    fast = head;
    while (fast && fast != tail) {
        fast = fast->next;
        if (fast != tail && fast->next != tail) {
            slow = slow->next;
            fast = fast->next;
        }
    }
    node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    node->val = slow->val;
    node->left = sort_list_to_bst_helper(head, slow);
    node->right = sort_list_to_bst_helper(slow->next, tail);
    return node;
}

struct TreeNode* sortedListToBST(struct ListNode* head) {
    if (!head)
        return NULL;
    return sort_list_to_bst_helper(head, NULL);
}
