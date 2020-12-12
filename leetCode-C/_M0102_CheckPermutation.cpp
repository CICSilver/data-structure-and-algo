#include <string>
#include <iostream>
#include <map>

using namespace std;

bool CheckPermutation(string s1, string s2)
{
    if(s1.size() != s2.size())
    {
        return false;
    }
    map<char, int> m1;
    map<char, int> m2;

    for(auto const& c:s1)
    {
        m1[c]++;
    }
    for(auto const& c:s2)
    {
        m2[c]++;
    }

    return (m1 == m2);
}