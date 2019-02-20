#if 0
148. Sort List
Medium

1174

63

Favorite

Share
Sort a linked list in O(n log n) time using constant space complexity.

Example 1:

Input: 4->2->1->3
Output: 1->2->3->4
Example 2:

Input: -1->5->3->4->0
Output: -1->0->3->4->5
Accepted
168,485
Submissions
499,289
#endif

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
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

void
split_list(struct ListNode *head, struct ListNode **f,
          struct ListNode **b)
{
    struct ListNode *slow, *fast;
    
    slow = head;
    fast = head->next;
    while (fast) {
        fast = fast->next;
        if (fast) {
            slow = slow->next;
            fast = fast->next;
        }
    }
    *f = head;
    *b = slow->next;
    slow->next = NULL;
}

struct ListNode *
merge_list(struct ListNode *f, struct ListNode *b)
{
    struct ListNode *result, *head, *p, *n;
    
    if (!f)
        return b;
    if (!b)
        return f;
#if 0
    if (f->val <= b->val) {
        result = f;
        result->next = merge_list(f->next, b);
    } else {
        result = b;
        result->next = merge_list(f, b->next);
    }
    return result;
#else
    head = p = NULL;
    while (f && b) {
        if (f->val <= b->val) {
            n = f;
            f = f->next;
        } else {
            n = b;
            b = b->next;
        }
        n->next = NULL;
        if (!head) {
            head = n;
            p = head;
        } else {
            p->next = n;
            p = p->next;
        }
    }
    p->next = f ? f : b;
    return head;
#endif
}

struct ListNode* sortList(struct ListNode* head) {
    struct ListNode *front, *back, *new;
    
    if (!head || !head->next)
        return head;
    split_list(head, &front, &back);
    new = merge_list(sortList(front), sortList(back));
    return new;
}
