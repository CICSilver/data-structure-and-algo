#include <vector>
#include <iostream>
#include <map>

using namespace std;

/**
 * @brief 
 * 给定一个大小为 n 的数组，找到其中的多数元素。多数元素是指在数组中出现次数大于 ⌊ n/2 ⌋ 的元素。
 * 你可以假设数组是非空的，并且给定的数组总是存在多数元素。
 * 
 */
int majorityElement(vector<int> &nums)
{
    
    map<int, int> numsAndCounts;
    int n = nums.size() / 2;
    for (auto const &n : nums)
    {
        numsAndCounts[n]++;
    }
    int res;
    for (auto const &p : numsAndCounts)
    {
        if(p.second > n)
        {
            res = p.first;
            break;
        }
    }
    return res;
}

int main()
{
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
    int res = majorityElement(nums);
    cout << res << endl;
}