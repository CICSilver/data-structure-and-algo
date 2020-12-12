#include <thread>
#include <vector>
#include <iostream>

using namespace std;

int getLeft(vector<int> &nums, int target)
{
    int res = 1;
    for (int i = 0; i < target; ++i)
    {
        res *= nums[i];
    }
    return res;
}

int getRight(vector<int> &nums, int target)
{
    int res = 1;
    for (int i = nums.size() - 1; i > target; --i)
    {
        res *= nums[i];
    }
    return res;
}

int getProduct(vector<int> &nums, int target)
{
    if (target == 0)
    {
        return getRight(nums, target);
    }
    else if (target == nums.size() - 1)
    {
        return getLeft(nums, target);
    }

    int left = getLeft(nums, target);
    int right = getRight(nums, target);
    return left * right;
}

vector<int> productExceptSelf(vector<int> &nums)
{
    vector<int> res;
    if(nums.size() == 0)
    {
        return res;
    }
    for (int i = 0; i < nums.size(); i++)
    {
        res.emplace_back(getProduct(nums, i));
    }

    for(auto const& n:res)
    {
        cout << n << ",";
    }
    cout << endl;

    return res;
}

int main()
{
    vector<int> nums = {1,2,3,4};
    productExceptSelf(nums);
}