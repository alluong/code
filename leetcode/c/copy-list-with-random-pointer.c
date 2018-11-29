/*
A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list.
*/
/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     struct RandomListNode *next;
 *     struct RandomListNode *random;
 * };
 */
struct RandomListNode *
new_node(int label)
{
    struct RandomListNode *node = (struct RandomListNode *)malloc(sizeof(struct RandomListNode));
    
    node->label = label;
    node->next = node->random = NULL;
    return node;
}
struct RandomListNode *copyRandomList(struct RandomListNode *head) {
    struct RandomListNode *pcopy, *copy_head, *p, *new, *q, *qc;
    
    p = head;
    if (!p)
        return NULL;
    copy_head = NULL;
    
    /* copy the list based on next pointer first */
    while (p) {
        new = new_node(p->label);
        if (!copy_head) {
            copy_head = new;
            pcopy = copy_head;
        } else {
            pcopy->next = new;
            pcopy = pcopy->next;
        }
        p = p->next;
    }
    
    /* copy random pointer */
    p = head;
    pcopy = copy_head;
    while (p) {
        if (p->random) {
            q = head;
            qc = copy_head;
            while (q && q != p->random) {
                q = q->next;
                qc = qc->next;
            }
            pcopy->random = qc;
        }
        p = p->next;
        pcopy = pcopy->next;
    }
    return copy_head;
}
