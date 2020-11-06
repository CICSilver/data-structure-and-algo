/*
 * @Author: CICSilver
 * @Date: 2020-10-24 05:50:43
 * @Description: leetcode 746题 动态规划
 * @LastEditTime: 2020-10-24 06:20:59
 * @LastEditors: CICSilver
 * @FilePath: /ben/leetCode/_746_minCostClimbingStairs.c
 */
#include <stdio.h>

#define MIN(a,b) a<b?a:b

//dp[0] = a[0]
//dp[1] = MIN{dp[0]+a[1],a[1]}
//dp[i] = MIN{dp[i-1]+a[i],dp[i-2]+a[i]} ,i>1
int minCostClimbingStairs(int* cost, int costSize)
{
    int dp[costSize];
    for(int i = 0;i<costSize;i++)
    {
        dp[i] = getDP(cost,dp,i);
    }
    return MIN(dp[costSize-1],dp[costSize-2]);
}

int getDP(int *a,int *dp,int i)
{
    if(i == 0)
    {
        return a[0];
    }

    if(i == 1)
    {
        return MIN(dp[0]+a[i], a[i]);
    }

    return MIN(dp[i-2]+a[i],dp[i-1]+a[i]);
}

int main()
{
    char *str = "abc";
    printf("%c\n",str[1]);
}