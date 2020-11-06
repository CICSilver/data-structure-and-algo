/*
 * @Author: CICSilver
 * @Date: 2020-10-28 15:17:23
 * @Description: 
 * @LastEditTime: 2020-10-28 17:53:32
 * @LastEditors: CICSilver
 * @FilePath: /ben/leetCode/_1207_uniqueOccurrences.cpp
 */
#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        std::map<int,int> map1;
        
        for(const auto& x:arr)
        {
            map1[x]++;
        }

        std::set<int> times;
        for(const auto& x:map1)
        {
            times.insert(x.second);
        }
        return map1.size == times.size;
    }
};
