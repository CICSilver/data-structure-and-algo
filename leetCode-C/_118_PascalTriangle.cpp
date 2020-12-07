#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> generate(int numRows)
{
    vector<vector<int>> res;
    if(numRows <= 0)
    {
        return res;
    }
    for (int n = 0; n < numRows; ++n)
    {
        vector<int> row;
        for (int k = 0; k <= n; ++k)
        {
            if(k == 0 || k ==n)
            {
                row.push_back(1);
                continue;
            }
            row.push_back(res[n - 1][k - 1] + res[n - 1][k]);
        }
        res.push_back(row);
    }
    return res;
}