#include <string>
#include <iostream>
#include <map>

using namespace std;

bool isUnique(string astr)
{
    if(astr == "")
    {
        return true;
    }
    if(astr.size() > 100)
    {
        return false;
    }

    map<char, int> m;
    for (auto const &c:astr)
    {
        m[c]++;
    }

    for(auto const& p:m)
    {
        if(p.second > 1)
        {
            return false;
        }
    }
    return true;
}

