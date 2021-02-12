#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

// 0,0 - 0,3 0,0 - 2,0
void setZeroes(vector<vector<int>> &matrix)
{
    if (matrix.size() == 0)
    {
        return;
    }
    int rows = matrix.size();
    int cols = matrix[0].size();

    unordered_set<int> zeroRow;
    unordered_set<int> zeroCol;

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            if (matrix[i][j] == 0)
            {
                zeroRow.insert(i);
                zeroCol.insert(j);
            }
        }
    }

    for (auto const &row : zeroRow)
    {
        for (int j = 0; j < cols; ++j)
        {
            matrix[row][j] = 0;
        }
    }

    for (auto const &col : zeroCol)
    {
        for (int i = 0; i < rows; ++i)
        {
            matrix[i][col] = 0;
        }
    }
}

int main(int argc, char *argv[])
{
    vector<vector<int>> matrix =
        {
            {0, 1, 2, 0},
            {3, 4, 5, 2},
            {1, 3, 1, 5}};
    setZeroes(matrix);
    for (int i = 0; i < matrix.size(); ++i)
    {
        for (int j = 0; j < matrix[0].size(); ++j)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}