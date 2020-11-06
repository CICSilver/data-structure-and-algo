#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int islandPerimeter(vector<vector<int>> &grid)
    {
        int meter[5] = {4, 3, 2, 1, 0};
        int sum = 0;
        bool isAdjacent = false;
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[0].size(); ++j)
            {
                if (grid[i][j] == 1)
                {
                    sum += 4;
                    if(i > 0 && grid[i-1][j] == 1)
                    {
                        sum -= 2;
                    }
                    if(j > 0 && grid[i][j - 1] == 1)
                    {
                        sum -=2;
                    }
                }
                
            }
        }
        return sum;
    }

    int adjacent(vector<vector<int>> &grid, int h, int w)
    {
        int height = grid.size();
        int width = grid[0].size();
        int sum = 0;

        if (h == 0)
        {
            if (w == 0)
            {
                sum += grid[h][w + 1];
                sum += grid[h + 1][w];
            }
            else if (w < width - 1)
            {
                sum += grid[h][w - 1];
                sum += grid[h + 1][w];
            }
            else
            {
                sum += grid[h][w - 1];
                sum += grid[h][w + 1];
                sum += grid[h + 1][w];
            }
        }
        else if (h == height - 1)
        {
            if (w == 0)
            {
                sum += grid[h - 1][w];
                sum += grid[h][w + 1];
            }
            else if (w < width - 1)
            {
                sum += grid[h][w - 1];
                sum += grid[h - 1][w];
            }
            else
            {
                sum += grid[h][w - 1];
                sum += grid[h][w + 1];
                sum += grid[h - 1][w];
            }
        }
        else
        {
            sum += grid[h][w - 1];
            sum += grid[h][w + 1];
            sum += grid[h - 1][w];
            sum += grid[h + 1][w];
        }

        return sum;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> grid = {
        {0, 1, 0, 0},
        {1, 1, 1, 0},
        {0, 1, 0, 0},
        {1, 1, 0, 0}};
    int res = s.islandPerimeter(grid);
    cout << res << endl;
}