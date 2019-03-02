#if 0
155. Min Stack
Easy

1521

161

Favorite

Share
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
Example:
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> Returns -3.
minStack.pop();
minStack.top();      --> Returns 0.
minStack.getMin();   --> Returns -2.
Accepted
269,373
Submissions
755,755
#endif

typedef struct {
    int top;
    int min;
    int size;
    int *val;
} MinStack;

/** initialize your data structure here. */
MinStack* minStackCreate(int maxSize) {
    MinStack *s;
    
    s = (int *)malloc(sizeof(MinStack));
    s->top = -1;
    s->min = INT_MAX;
    s->size = maxSize;
    s->val = (int *)malloc(sizeof(int) * maxSize);
    return s;
}

void minStackPush(MinStack* obj, int x) {
    /* check for full */
    if (obj->top == obj->size - 1)
        return;
    
    /* check for empty */
    if (obj->top == -1)
        obj->top = 0;
    else
        ++obj->top;
    obj->val[obj->top] = x;

    /* update min */
    if (x < obj->min)
        obj->min = x;
}  

void minStackPop(MinStack* obj) {
    /* check for empty */
    if (obj->top == -1)
        return;
    if (obj->top == 0) {
        obj->top = -1;
        obj->min = INT_MAX;
    } else {
        if (obj->val[obj->top] == obj->min) {
            int ii;
            
            obj->min = obj->val[0];
            for (ii = 1; ii < obj->top; ii++) {
                if (obj->min > obj->val[ii])
                    obj->min = obj->val[ii];
            }
        }
        --obj->top;
    }
}

int minStackTop(MinStack* obj) {
    return obj->val[obj->top];
}

int minStackGetMin(MinStack* obj) {
    if (obj->top == -1)
        return INT_MIN;
    return obj->min;
}

void minStackFree(MinStack* obj) {
    free(obj->val);
    free(obj);
    obj = NULL;
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * struct MinStack* obj = minStackCreate(maxSize);
 * minStackPush(obj, x);
 * minStackPop(obj);
 * int param_3 = minStackTop(obj);
 * int param_4 = minStackGetMin(obj);
 * minStackFree(obj);
 */
