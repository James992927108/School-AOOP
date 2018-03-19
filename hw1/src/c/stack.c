#include <stdlib.h>
#include "stack.h"

void push(struct stack* this, int x)
{
    SN* newnode = malloc(sizeof(SN));
    newnode->next = this->top;
    newnode->data = x;
    this->top = newnode;
}
int pop(struct stack* this)
{
    SN* tempnode = this->top;
    this->top = this->top->next;
    int tempnode_data = tempnode->data;
    free(tempnode);
    return tempnode_data;
}

struct stack *new_stack()
{
    struct stack* stk = malloc(sizeof(struct stack));
    return stk;
}

void delete_stack(struct stack *stk)
{
    free(stk);
}

