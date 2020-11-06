/*
 * @Author: CICSilver
 * @Date: 2020-10-20 06:09:23
 * @Description: 
 * @LastEditTime: 2020-10-20 11:59:40
 * @LastEditors: CICSilver
 * @FilePath: /ben/leetCode/findNumberIn2DArray.c
 */
#include <stdio.h>

/**
 * @description: 
 * 在一个 n * m 的二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
 * 示例:
 * 
 * 现有矩阵 matrix 如下：
 * 
 * [
 *   [1,   4,  7, 11, 15],
 *   [2,   5,  8, 12, 19],
 *   [3,   6,  9, 16, 22],
 *   [10, 13, 14, 17, 24],
 *   [18, 21, 23, 26, 30]
 * ]
 * 给定 target = 5，返回 true。
 * 
 * 给定 target = 20，返回 false。

 */
int findNumberIn2DArray(int** matrix, int matrixSize, int* matrixColSize, int target)
{
    if(matrix == NULL || matrixSize == 0 || *matrixColSize == 0)
    {
        return 0;
    }

    int root_row = 0;
    int root_col = matrixColSize[0] - 1;
    int *p = matrix;
    
    // printf("row = %d, col = %d, root_val = %d\n",root_row,root_col,*(p+root_row*root_col+root_col));
    
    if(findNumInSub(matrix,root_col,target,root_row,root_col))
    {
        return 1;
    }
    return 0;
}

int findNumInSub(int** matrix,int maxCol,int target,int root_row,int root_col)
{
    int *p = matrix;
    int root_val = *(p+root_row*root_col+root_col);
    // printf("row = %d, col = %d\n",root_row,root_col);
    // printf("%d\n",root_val);
    //递归出口
    if(target == root_val)
    {
         return 1;
    }
    
    if(target < root_val && root_row>=0)
    {
        // printf("cur = (%d,%d) = %d\n",root_row,root_col,matrix[root_row][root_col]);
        findNumInSub(matrix,maxCol,target,--root_row,root_col);
    }
    
    if(target > root_val && root_col<=maxCol)
    {
        // printf("cur = (%d,%d) = %d\n",root_row,root_col,matrix[root_row][root_col]);
        findNumInSub(matrix,maxCol,target,root_row,++root_col);
    }
    return 0;

}

int main()
{
    int target;
    scanf("%d",&target);
    int matrix[5][5] =  {
                            {1,   4,  7, 11, 15},
                            {2,   5,  8, 12, 19},
                            {3,   6,  9, 16, 22},
                            {10, 13, 14, 17, 24},
                            {18, 21, 23, 26, 30}
                        };
    int matrixCol[5] = {5,5,5,5,5};
    int res = findNumberIn2DArray(matrix, 5,matrixCol,target);
    printf("%d\n",res);
}