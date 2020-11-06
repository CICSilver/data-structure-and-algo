#include <iostream>
#include <vector>
using namespace std;

#define MIN(a, b) a < b ? a : b

class Solution
{
public:
    //dp[i][j] = 0 ,i == 0 && j == 0
    //dp[i][j] = dp[i-1][j] + a[i][j]  ,i > 0 && j == 0
    //dp[i][j] = dp[i][j-1] + a[i][j] ,i == 0 && j > 0
    //dp[i][j] = MIN{dp[i-1][j]+a[i][j],dp[i][j-1]+a[i][j]} ,i >0 && j > 0
    int minPathSum(vector<vector<int>> &grid)
    {
        int rows = grid.size();
        int cols = grid[0].size();
        if(rows == 0 || cols == 0)
        {
            return 0;
        }
        vector<vector<int>> dp(grid);
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (i == 0 && j == 0)
                {
                    dp[i][j] = grid[i][j];
                }
                else if (i > 0 && j == 0)
                {
                    dp[i][j] = dp[i - 1][j] + grid[i][j];
                }
                else if (i == 0 && j > 0)
                {
                    dp[i][j] = dp[i][j - 1] + grid[i][j];
                }
                else
                {
                    dp[i][j] = MIN(dp[i - 1][j] + grid[i][j], dp[i][j - 1] + grid[i][j]);
                }
            }
        }

        for (auto &q : dp)
        {
            for (auto p : q)
            {
                cout << p << " ";
            }
            cout << endl;
        }
        cout << endl;

        for (auto it_vv = grid.begin(); it_vv != grid.end(); it_vv++)
        {
            for (auto it_v = it_vv->begin(); it_v != it_vv->end(); it_v++)
            {
                cout << *it_v << " ";
            }
            cout << endl;
        }

        cout << dp[rows - 1][cols - 1] << endl;
        return dp[rows - 1][cols - 1];
    }
};

int main()
{
    int row = 3;
    int col = 3;
    int nums_arr[row][col] = {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}};
    vector<vector<int>> nums(row, vector<int>(col));
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            nums[i][j] = nums_arr[i][j];
        }
    }
    Solution s;
    s.minPathSum(nums);
}