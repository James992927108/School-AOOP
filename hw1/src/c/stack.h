#ifndef __STACK_H__
#define __STACK_H__

typedef struct StackNode
{
    int data;
    struct StackNode *next;
}SN;

struct stack
{ 
    SN *top;
};


void push(struct stack* this, int x);
int pop(struct stack* this);
struct stack *new_stack();
void delete_stack(struct stack *stk);
#endif