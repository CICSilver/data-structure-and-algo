#include <vector>
#include <iostream>

using namespace std;

// dp[2][1] = dp[1][0] + dp[1][1]
// dp[n][m] = dp[n-1][m-1] + dp[n-1][m]
//          = 1,    n = 0 || m = 0 || m = n
// 1
// 1 1
// 1 2 1, (i)k =2
// 1 3 3 1, (i)k = 3
// 1 4 6 4 1, k = 4
// 1 4 6 4 1 1, k=5
// 1 6 15 20 15 6 1,

//  思路: 滚动数组优化的动态规划，减少无用数组的存储，只对上一状态进行存储以推进结果计算
vector<int> getRow(int rowIndex)
{
    vector<int> res(rowIndex + 1, 1);
    for (int i = 2; i < res.size(); ++i)
    {
        for (int j = i - 1; j > 0; --j)
        {
            res[j] = res[j] + res[j - 1];
        }
    }
    return res;
}