#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    vector<vector<string>> res;
    if(strs.size() == 0)
    {
        return res;
    }
    map<string, vector<string>> map;
    for(auto const& str:strs)
    {
        string key = str;
        sort(key.begin(), key.end());
        map[key].push_back(str);
    }

    for(auto const& p:map)
    {
        res.push_back(p.second);
    }

    return res;
}
