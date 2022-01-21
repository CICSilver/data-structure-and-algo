#include <vector>
#include <iostream>

using namespace std;

// 原地排序
// 1. 冒泡
void sortColors(vector<int> &nums)
{
    for (int i = 0; i < nums.size(); ++i)
    {
        for (int j = 0; j < nums.size() - (i + 1); ++j)
        {
            if (nums[j] > nums[j + 1])
            {
                int temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;
            }
        }
    }
}

int main(int argc, char *argv[])
{
    vector<int> nums = {2, 0, 2, 1, 1, 0};
    for (auto const &i : nums)
    {
        cout << i << " ";
    }
    cout << endl;

    sortColors(nums);

    // for (auto const &i : nums)
    // {
    //     cout << i << " ";
    // }
    cout << endl;
    return 0;
}