/**
 *     void Push(int val);
    int Peek();
    void Pop();

    bool isFull();
    bool isEmpty();
*/
#include "Stack.h"
#include <iostream>

void Stack::Push(int val)
{
    if (isFull())
    {
        return;
    }

    stack_[curLen_++] = val;
}

int Stack::Peek()
{
    return isEmpty() ? NULL : stack_[curLen_ - 1];
}

void Stack::Pop()
{
    if (isEmpty())
    {
        return;
    }
    curLen_--;
}

bool Stack::isFull()
{
    return curLen_ == capacity_;
}

bool Stack::isEmpty()
{
    return curLen_ <= 0;
}
