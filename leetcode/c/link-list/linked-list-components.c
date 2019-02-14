#if 0
817. Linked List Components
Medium

180

419

Favorite

Share
We are given head, the head node of a linked list containing unique integer values.

We are also given the list G, a subset of the values in the linked list.

Return the number of connected components in G, where two values are connected if they appear consecutively in the linked list.

Example 1:

Input: 
head: 0->1->2->3
G = [0, 1, 3]
Output: 2
Explanation: 
0 and 1 are connected, so [0, 1] and [3] are the two connected components.
Example 2:

Input: 
head: 0->1->2->3->4
G = [0, 3, 1, 4]
Output: 2
Explanation: 
0 and 1 are connected, 3 and 4 are connected, so [0, 1] and [3, 4] are the two connected components.
Note:

If N is the length of the linked list given by head, 1 <= N <= 10000.
The value of each node in the linked list will be in the range [0, N - 1].
1 <= G.length <= 10000.
G is a subset of all values in the linked list.
#endif

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool
is_sub_set(int val, int *set, int n)
{
    int ii;
    
    for (ii = 0; ii < n; ii++) {
        if (set[ii] == val)
            return true;
    }
    return false;
}

int numComponents(struct ListNode* head, int* G, int GSize) {
    int count;
    bool start;
    
    if (!head)
        return 0;
    count = 0;
    start = false;
    while (head) {
        if (is_sub_set(head->val, G, GSize)) {
            if (!start) {
                /* mark start of a new connected component and increment count */
                start = true;
                ++count;
            }
        } else {
            start = false;
        }
        head = head->next;
    }
    return count;
}
