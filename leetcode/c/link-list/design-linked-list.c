#if 0
707. Design Linked List
Easy

236

70

Favorite

Share
Design your implementation of the linked list. You can choose to use the singly linked list or the doubly linked list. A node in a singly linked list should have two attributes: val and next. val is the value of the current node, and next is a pointer/reference to the next node. If you want to use the doubly linked list, you will need one more attribute prev to indicate the previous node in the linked list. Assume all nodes in the linked list are 0-indexed.

Implement these functions in your linked list class:

get(index) : Get the value of the index-th node in the linked list. If the index is invalid, return -1.
addAtHead(val) : Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list.
addAtTail(val) : Append a node of value val to the last element of the linked list.
addAtIndex(index, val) : Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted.
deleteAtIndex(index) : Delete the index-th node in the linked list, if the index is valid.
Example:

MyLinkedList linkedList = new MyLinkedList();
linkedList.addAtHead(1);
linkedList.addAtTail(3);
linkedList.addAtIndex(1, 2);  // linked list becomes 1->2->3
linkedList.get(1);            // returns 2
linkedList.deleteAtIndex(1);  // now the linked list is 1->3
linkedList.get(1);            // returns 3
Note:

All values will be in the range of [1, 1000].
The number of operations will be in the range of [1, 1000].
Please do not use the built-in LinkedList library.
#endif

struct node {
    int val;
    struct node *next;
};

typedef struct {
    struct node *list;
} MyLinkedList;

/** Initialize your data structure here. */
MyLinkedList* myLinkedListCreate() {
    MyLinkedList *linklist = (MyLinkedList *)malloc(sizeof(MyLinkedList));
    
    linklist->list = NULL;
    return linklist;
}

/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
int myLinkedListGet(MyLinkedList* obj, int index) {
    struct node *p;
    int ii;
    
    p = obj->list;
    for (ii = 0; ii < index; ii++) {
        if (p)
            p = p->next;
    }
    if (p)
        return p->val;
    return -1;
}

/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    struct node *node = (struct node *)malloc(sizeof(struct node));
    
    node->val = val;
    node->next = obj->list;
    obj->list = node;
}

/** Append a node of value val to the last element of the linked list. */
void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    struct node *node = (struct node *)malloc(sizeof(struct node));
    struct node *p;
    
    node->val = val;
    node->next = NULL;
    p = obj->list;
    if (!p)
        p->next = node;
    else {
        while (p->next) {
            p = p->next;
        }
        p->next = node;
    }
}

/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    struct node *p, *pp, *node;
    int ii;
    
    p = obj->list;
    pp = NULL;
    for (ii = 0; ii < index; ii++) {
        if (p) {
            pp = p;
            p = p->next;
        } else {
            if (ii != index)
                return;
        }
    }
    node = (struct node *)malloc(sizeof(struct node));
    node->val = val;
    if (pp) {
        pp->next = node;
    } else {
        obj->list = node;
    }
    node->next = p;
}

/** Delete the index-th node in the linked list, if the index is valid. */
void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    struct node *p, *pp;
    int ii;
    
    p = obj->list;
    pp = NULL;
    for (ii = 0; ii < index; ii++) {
        if (p) {
            pp = p;
            p = p->next;
        }
    }
    if (p) {
        pp->next = p->next;
        free(p);
    }
}

void myLinkedListFree(MyLinkedList* obj) {
    struct node *p, *tmp;
    
    p = obj->list;
    while (p) {
        tmp = p;
        p = p->next;
        free(tmp);
    }
    free(obj);
}

/**
 * Your MyLinkedList struct will be instantiated and called as such:
 * struct MyLinkedList* obj = myLinkedListCreate();
 * int param_1 = myLinkedListGet(obj, index);
 * myLinkedListAddAtHead(obj, val);
 * myLinkedListAddAtTail(obj, val);
 * myLinkedListAddAtIndex(obj, index, val);
 * myLinkedListDeleteAtIndex(obj, index);
 * myLinkedListFree(obj);
 */
