#ifndef _STACK_H
#define _STACK_H

class Stack
{
public:
    Stack(int size) : capacity_(size), stack_(new int[size]){};
    ~Stack();

    void Push(int val);
    int Peek();
    void Pop();

    bool isFull();
    bool isEmpty();

private:
    int *stack_ = nullptr;
    int capacity_;
    int curLen_ = 0;
};

Stack::~Stack()
{
    delete [] stack_;
    stack_ = nullptr;
}

#endif