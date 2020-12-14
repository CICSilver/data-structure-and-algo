#include <iostream>
#include <map>
#include <vector>

using namespace std;

bool containsDuplicate(vector<int> &nums)
{
    map<int, int> m;
    for(auto const& n:nums)
    {
        m[n]++;
    }

    for(auto const& p:m)
    {
        if(p.second >= 2)
        {
            return true;
        }
    }

    return false;
}

int main()
{
    vector<int> nums = {1, 2, 3, 0};
    cout << containsDuplicate(nums) << endl;
}