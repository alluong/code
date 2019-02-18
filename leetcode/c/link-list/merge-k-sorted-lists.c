#if 0
23. Merge k Sorted Lists
Hard

2007

125

Favorite

Share
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

Example:

Input:
[
  1->4->5,
  1->3->4,
  2->6
]
Output: 1->1->2->3->4->4->5->6
Accepted
333,569
Submissions
1,021,717
#endif

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *
merge2Lists(struct ListNode *list1, struct ListNode *list2)
{
    struct ListNode *p, *nn, *head;

    if (!list1 && !list2)
        return NULL;
    if (!list1)
        return list2;
    if (!list2)
        return list1;
    head = NULL;
    while (list1 && list2) {
        if (list1->val <= list2->val) {
            nn = list1;
            list1 = list1->next;
        } else {
            nn = list2;
            list2 = list2->next;
        }
        if (!head) {
            head = nn;
            p = head;
        } else {
            p->next = nn;
            p = p->next;
        }
    }
    if (list1)
        p->next = list1;
    else
        p->next = list2;
    return head;
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    int ii, jj, nn;

    /* terminating conditions for recursive call */
    if (!listsSize)
        return NULL;
    if (listsSize == 1)
        return lists[0];
    nn = 0;
    for (ii = 0; ii < listsSize; ii += 2) {
        /* if both lists are valid, merge, else return first list */
        if (ii < listsSize - 1)
            lists[nn] = merge2Lists(lists[ii], lists[ii + 1]);
        else
            lists[nn] = lists[ii];
        nn++;
    }
    return mergeKLists(lists, nn);
}
