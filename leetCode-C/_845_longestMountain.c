/*
 * @Author: CICSilver
 * @Date: 2020-10-25 05:59:29
 * @Description: 
 * @LastEditTime: 2020-10-25 06:23:56
 * @LastEditors: CICSilver
 * @FilePath: /ben/leetCode/_845_longestMountain.c
 */
#include <stdio.h>
#define MAX(a, b) a > b ? a : b
#define MIN(a, b) a < b ? a : b

//left[i] = 0 , i == 1 || (a[i] <= a[i-1])
//left[i] = left[i - 1] + 1, a[i] > a[i - 1]
//right[i] = 0, i == Asize - 1 || (a[i] >= a[i+1])
//right[i] = right[i + 1] + 1, a[i] < a[i + 1]
//dp[i] = left[i] + right[i]
int longestMountain(int *A, int ASize)
{
    if(ASize == 0 || A == NULL)
    {
        return NULL;
    }
    int dp[ASize];
    int left[ASize];
    int right[ASize];
    int sum = 0;
    for (int i = ASize - 1; i >= 0; --i)
    {
        right[i] = getRight(A, right, ASize, i);
        printf("right[%d] = %d\n",i, right[i]);
    }
    for (int i = 0; i < ASize; ++i)
    {
        left[i] = getLeft(A, left, i);
        printf("left[%d] = %d\n",i, left[i]);
        if(left[i] == 0 || right[i] == 0)
        {
            dp[i] = 0;
            continue;
        }
        dp[i] = left[i] + right[i];
        if(dp[i] != 0)
        {
            ++dp[i];
        }
        sum = MAX(dp[i], sum);
    }
    return sum;
}

int getLeft(int *A, int *left, int i)
{
    if (i == 0)
    {
        return 0;
    }
    if (A[i] > A[i - 1])
    {
        return left[i - 1] + 1;
    }
    return 0;
}

int getRight(int *A, int *right, int ASize, int i)
{
    if (i == ASize - 1)
    {
        return 0;
    }
    if (A[i] > A[i + 1])
    {
        return right[i + 1] + 1;
    }
    return 0;
}

int main()
{
    int A[] = {2, 3};
    int len = sizeof(A) / sizeof(A[0]);
    int t = longestMountain(A, len);
    printf("res = %d\n", t);
}