/*
 * @Author: CICSilver
 * @Date: 2020-10-25 08:47:16
 * @Description: 
 * @LastEditTime: 2020-10-25 08:53:59
 * @LastEditors: CICSilver
 * @FilePath: /ben/leetCode/_J42_maxSubArray.c
 */
#include <stdio.h>
#define MAX(a,b) a>b?a:b

int maxSubArray(int* nums, int numsSize)
{
    int dp[numsSize];
    int max = nums[0];
    for(int i = 0;i<numsSize;i++)
    {
        dp[i] = getDP(nums,dp,i);
        max = MAX(dp[i],max);
    }
    return max;
}

int getDP(int* nums, int* dp, int i)
{
    if(i == 0)
    {
        return nums[i];
    }
    return MAX(dp[i-1] + nums[i], nums[i]);
}

int main()
{
    int nums[] = {-2,1,-3,4,-1,2,1,-5,4};
    int max = maxSubArray(nums,9);
    printf("max = %d\n",max);
}