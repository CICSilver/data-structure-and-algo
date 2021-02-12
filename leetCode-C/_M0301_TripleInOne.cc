#include <iostream>
#include <vector>
#include <memory>
#include <string.h>

using namespace std;

/**
 * Your TripleInOne object will be instantiated and called as such:
 * TripleInOne* obj = new TripleInOne(stackSize);
 * obj->push(stackNum,value);
 * int param_2 = obj->pop(stackNum);
 * int param_3 = obj->peek(stackNum);
 * bool param_4 = obj->isEmpty(stackNum);
 */
// 三个栈 0 1 2
// 传入编号 0-2
// stack0: [stack_arr[stackSize * 0], stack_arr[stackSize - 1]]
// stack1: [stack_arr[stackSize * 1], stack_arr[2*stackSize - 1]]
// 非空当前指针为：stack_arr[stackSize * stackNum + stack_0_size]
class TripleInOne
{
public:
    TripleInOne(int stackSize)
    {
        this->capacity = stackSize;
        int realSize = stackSize * 3;
        this->stack_arr = (int *)calloc(realSize, sizeof(int));
    }

    void push(int stackNum, int value)
    {
        if (stackNum < 0 || stackNum > 2)
        {
            return;
        }
        // 指定栈的起始地址 + 已用空间(获取指定栈地址？)
        int *stack = this->stack_arr + (capacity * stackNum);
        int *curSize = cSize(stackNum);
        if (*curSize >= capacity)
        {
            return;
        }
        // 栈非满
        stack += (*curSize);
        *stack = value;
        ++(*curSize);
    }

    int pop(int stackNum)
    {
        if (isEmpty(stackNum))
        {
            return -1;
        }
        auto curSize = cSize(stackNum);
        int *stack = this->stack_arr + (capacity * stackNum) + *curSize;
        *stack = 0;
        --(*curSize);
        return 1;
    }

    int peek(int stackNum)
    {
        if (isEmpty(stackNum))
        {
            return -1;
        }
        auto stack = this->stack_arr + (capacity * stackNum) + *cSize(stackNum) - 1;
        int ret = *(stack);
        return ret;
    }

    bool isEmpty(int stackNum)
    {
        auto ret = false;
        switch (stackNum)
        {
        case 0:
            if (stack_0_size == 0)
            {
                ret == true;
            }
            break;
        case 1:
            if (stack_1_size == 0)
            {
                ret == true;
            }
            break;
        case 2:
            if (stack_2_size == 0)
            {
                ret == true;
            }
            break;
        }
        return ret;
    }

    int Size(int stackNum)
    {
        return *cSize(stackNum);
    }
    ~TripleInOne()
    {
        memset(this->stack_arr, 0, sizeof(this->stack_arr));
        delete[] this->stack_arr;
    }

private:
    int *stack_arr;
    int capacity;
    int stack_0_size;
    int stack_1_size;
    int stack_2_size;

    int *cSize(int stackNum)
    {
        int *curSize = nullptr;
        switch (stackNum)
        {
        case 0:
            curSize = &stack_0_size;
            break;
        case 1:
            curSize = &stack_1_size;
            break;
        case 2:
            curSize = &stack_2_size;
            break;
        default:
            break;
        }
        return curSize;
    }
};

int main()
{
    TripleInOne *tpo = new TripleInOne(3);
    tpo->push(0, 1);
    tpo->push(0, 2);
    tpo->push(1, 2);
    tpo->pop(0);
    cout << tpo->peek(0) << endl;
    cout << tpo->peek(1) << endl;
}