#ifndef __STACK_H__
#define __STACK_H__

class StackNode
{
  private:
    int data;
    StackNode *next;
  public:
    StackNode() : data(0)
    {
        next = 0;
    }
    StackNode(int x) : data(x)
    {
        next = 0;
    }
    StackNode(int x, StackNode *nextNode) : data(x), next(nextNode){};
    friend class StackList;
};
class StackList
{
  private:
    StackNode *top; // remember the address of top element
    int size;       // number of elements in Stack
  public:
    StackList() : size(0), top(0){};
    void push(int x);
    int pop();
    bool IsEmpty();
    int topvalue();
    // int getSize();
};

#endif