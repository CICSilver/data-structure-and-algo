/*
 * @Author: CICSilver
 * @Date: 2020-10-24 05:06:12
 * @Description: leetcode 第198题 
 * @LastEditTime: 2020-10-24 05:34:45
 * @LastEditors: CICSilver
 * @FilePath: /ben/leetCode/_198_rob.c
 */
#include <stdio.h>
#define MAX(a,b) a>b?a:b

//dp[i] = a[0], i = 0;
//dp[i] = MAX{dp[0], a[1]}, i = 1;
//dp[i] = MAX{dp[i-2]+a[i], dp[i-1]}, i>1;

int rob(int* nums, int numsSize)
{
    if(numsSize == 0)
    {
        return 0;
    }
    int dp[numsSize];
    for(int i = 0;i<numsSize;i++)
    {
        dp[i] = getDP(i, dp, nums);
    }
    
    return dp[numsSize - 1];
}

int getDP(int n,int* dp, int* nums)
{
    if(n == 0)
    {
        return nums[0];
    }

    if(n == 1)
    {
        return MAX(dp[0],nums[1]);
    }

    return MAX((dp[n - 2]+nums[n]),dp[n-1]);
}

int main()
{
    int arr[5] = {2,7,9,3,1};
    int res = rob(arr,5);

    printf("%d\n",res);
}