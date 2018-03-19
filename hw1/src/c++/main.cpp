#include <iostream>
#include "stack.h"

using std::cout;
using std::endl;

const int NUM_ITEMS = 200;
int main()
{
    StackList stk1;
    StackList stk2;

    //cout << "before push" << stk2.topvalue() << endl;

    for (int i = 0; i < NUM_ITEMS; i++)
    {
        stk1.push(100 + i);
        stk2.push(600 + i);
    }

    //cout << "after push" << stk2.topvalue() << endl;

    cout << "Dump of stack 1:" << endl;
    //cout << "before pop " << stk2.topvalue() << endl;
    for (int i = 0; i < NUM_ITEMS; i++)
    {
        cout << stk1.pop() << endl;
    }
    //cout << "after pop " << stk2.topvalue() << endl;

    cout << "Dump of stack 2:" << endl;
    for (int i = 0; i < NUM_ITEMS; i++)
    {
        cout << stk2.pop() << endl;
    }

    return 0;
}
