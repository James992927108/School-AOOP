#include <iostream>
#include "stack.h"
void StackList::push(int x)
{
    if (IsEmpty())
    {
        top = new StackNode(x);
        size++;
    }
    else
    {
        StackNode *newnode = new StackNode(x); // Push_front() in Linked list
        newnode->next = top;
        top = newnode;
        size++;
    }
    //cout << "push --" << size << "\n";
}

int StackList::pop()
{
    //std::cout << "--" << size << "\n";

    if (IsEmpty())
    {
        std::cout << "Stack is empty.\n";
        return 0;
    }
    StackNode *deletenode = top;
    int popvalue = top->data;

    top = top->next;
    delete deletenode;
    deletenode = 0;
    size--;

    return popvalue;
}

bool StackList::IsEmpty()
{
    return (size == 0); // if size==0, return true
}

int StackList::topvalue(){

    if (IsEmpty()) {
        std::cout << "Stack is empty.\n";
        return -1;
    }
    return top->data;
}

// int StackList::getSize(){

//     return size;
// }