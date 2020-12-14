#include <string>
#include <map>
#include <cstdlib>
#include <iostream>

using namespace std;

// size相同，两个1  （update）
// size不同，一个3/1 (del/add)
bool oneEditAway(string first, string second)
{
    int sizeDiff = abs((int)(first.size() - second.size()));
    bool sameSize = false;
    bool res = true;
    if (sizeDiff > 1)
    {
        return false;
    }
    if (sizeDiff == 0)
    {
        sameSize = true;
    }
    bool diffOnce = false;
    map<char, int> map;
    for (auto const &c : first)
    {
        map[c]++;
    }
    for (auto const &c : second)
    {
        map[c]++;
    }

    int oneCount = 0;
    // FIXME 考虑顺序问题,ab,bc和ab,ac
    for (auto const &p : map)
    {
        if (p.second != 2)
        {
            if (diffOnce)
            {
                res = false;
            }
            diffOnce = true;
            if(p.second == 1)
            {
                ++oneCount;
            }
        }
    }
    if (sameSize && oneCount == 2)
    {
        res = true;
    }
    return res;
}

int main()
{
    string s1 = "a";
    string s2 = "c";

    cout << oneEditAway(s1, s2) << endl;
}