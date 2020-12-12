#include <string>
#include <iostream>
#include <map>

using namespace std;

bool canPermutePalindrome(string s)
{
    map<char, int> map;

    for (auto const &c : s)
    {
        map[c]++;
    }

    //记录是否有1出现
    bool flag = false;
    for (auto const &p : map)
    {
        if (p.second%2 != 0)
        {
            if (flag)
            {
                return false;
            }
            else
            {
                flag = true;
            }
        }
    }
    return true;
}