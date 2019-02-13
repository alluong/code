/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Note that an empty string is also considered valid.

Example 1:

Input: "()"
Output: true
Example 2:

Input: "()[]{}"
Output: true
Example 3:

Input: "(]"
Output: false
Example 4:

Input: "([)]"
Output: false
Example 5:

Input: "{[]}"
Output: true
*/
enum symbol {
    BRACE = 1,
    BRACKET,
    PAREN
};
struct node {
    struct node *next;
    enum symbol type;    
};

struct node *
push(struct node **head, struct node *node)
{
    if (!*head) {
        *head = node;
    } else {
        node->next = *head;
        *head = node;
    }
    return *head;
}

bool
pop(struct node **head, enum symbol type)
{
    struct node *tmp;

    if (*head && (*head)->type == type) {
        tmp = *head;
        *head = (*head)->next;
        free(tmp);
        return true;
    }
    return false;
}

bool isValid(char* s) {
    struct node *head, *node;
    bool rc;

    rc = true;
    if (!s) {
        return rc;
    }
    head = NULL;
    while (*s) {
        switch (*s) {
            case '{':
                node = malloc(sizeof(struct node));
                node->type = BRACE;
                node->next = NULL;
                head = push(&head, node);
                rc = false;
                break;
            case '}':
                if (!pop(&head, BRACE))
                    return false;
                rc = true;
                break;
            case '[':
                node = malloc(sizeof(struct node));
                node->type = BRACKET;
                node->next = NULL;
                head = push(&head, node);
                rc = false;
                break;
            case ']':
                if (!pop(&head, BRACKET))
                    return false;
                rc = true;
                break;
            case '(':
                node = malloc(sizeof(struct node));
                node->type = PAREN;
                node->next = NULL;
                head = push(&head, node);
                rc = false;
                break;
            case ')':
                if (!pop(&head, PAREN))
                    return false;
                rc = true;
                break;
            default:
                break;
        }
        ++s;
    }
    return (rc && !head);
}
