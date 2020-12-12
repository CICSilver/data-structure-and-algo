#include <vector>
#include <iostream>

using namespace std;

// 所有操作均假定栈非空
class MinStack
{
private:
    vector<int> nums;
    int min = INT32_MAX;

public:
/** initialize your data structure here. */
#define MIN(a, b) a < b ? a : b;
    MinStack()
    {
    }

    void push(int x)
    {
        nums.push_back(x);
        min = MIN(min, x);
    }

    void pop()
    {
        auto it = nums.end();
        nums.erase(--it);
        if (nums.size() > 0)
        {
            min = nums[0];
            for (auto const &num : nums)
            {
                min = MIN(min, num);
            }
        }
        else
        {
            min = INT32_MAX;
        }
    }

    int top()
    {
        return nums[nums.size() - 1];
    }

    int getMin()
    {
        return min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main()
{
    MinStack stack;
    stack.push(0);
    stack.push(1);
    stack.push(0);

    int min = stack.getMin();

    cout << min << endl;
}