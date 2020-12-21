#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

void Swap(int &a, int &b)
{
    auto temp = a;
    a = b;
    b = temp;
}

// * 要求： 不占用额外内存空间
void rotate(vector<vector<int>> &matrix)
{
    int row = matrix.size();
    int col = matrix[0].size();

    if(row == 0 || col == 0 || row != col)
    {
        return;
    }

    for (int i = 0; i < row; ++i)
    {
        reverse(matrix[i].begin(), matrix[i].end());
    }

    // 分别以 (0,col) (1,col - 1) (2, col - 2) ...... (row - 2, col - (row - 2))为起点
    // 以对角线为轴做镜像

    // 0,2 ---- 1,3
    // 0,1 ---- 2,3
    // 0,0 ---- 3,3

    for (int i = 0; i < row - 1; ++i)
    {
        int curCol = col - i - 1;
        for (int j = 0; j < curCol; ++j)
        {
            Swap(matrix[i][j], matrix[col - j - 1][curCol]);
            // printf("1\n");
        }
        // printf("2\n");
    }
}

int main()
{
    vector<vector<int>> matrix;
    int count = 1;
    for (int i = 0; i < 3; ++i)
    {
        vector<int> row;
        for (int j = 0; j < 3; ++j)
        {
            row.emplace_back(count++);
        }
        matrix.emplace_back(row);
    }

    for (auto v_row : matrix)
    {
        for (auto i : v_row)
        {
            printf("%3d ", i);
        }

        printf("\n");
    }

    printf("============ reverse =============\n");
    rotate(matrix);

    for (auto v_row : matrix)
    {
        for (auto i : v_row)
        {
            printf("%3d ", i);
        }

        printf("\n");
    }
}