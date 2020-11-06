/*
 * @Author: CICSilver
 * @Date: 2020-10-19 07:03:50
 * @Description: 
 * @LastEditTime: 2020-10-19 08:29:20
 * @LastEditors: CICSilver
 * @FilePath: /ben/leetCode/_53_maxSubArray.c
 */

#include <stdio.h>

#define MAX(a,b) a>b?a:b
/**
 * @description: 
 * 给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），
 * 返回其最大和。
 * 
 * 示例:
 * 
 * 输入: [-2,1,-3,4,-1,2,1,-5,4]
 * 输出: 6
 * 解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
 * 进阶:
 * 
 * 如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的分治法求解
 * 
 * 思路:
 * 以每个序列的结束位置为标志，遍历所有以该标志结尾的序列，取出最大值使其为f[i]，只要获取到所有f[i]再判断最大值即可
 * 动态规划思路：存在关系
 * f(i) = MAX(f(i-1)+a(i),a(i))
 * 因为f(i-1)是前i-1个数的最大和，那么以a(i)结尾的连续序列中，只要判断之前的最大和加上a(i)是否比单独的a(i)大即可
 * @param {int* nums, int numsSize} 
 * @return {int} 
 */
int maxSubArray(int* nums, int numsSize)
{
    int dp[numsSize];
    int max = nums[0];
    for(int i = 0;i<numsSize;i++)
    {
        // printf("nums[%d] = %d\n", i,nums[i]);
        dp[i] = getMaxSub(nums,i);
        max = MAX(max,dp[i]);
    }
    return max;
}

int getMaxSub(int *nums,int i)
{
    int max = nums[i];
    int sum = 0;
    for(int t = i;t>=0;t--)
    {
        sum+=nums[t];
        max =MAX(max,sum);
    }
    // printf("max = %d\n",max);
    return max;
}
/**
 * @description: 动态规划思路 实现 最大连续子序列
 */
int dp_maxSubArray(int* nums, int numsSize)
{
    int dp[numsSize];
    //f(0)等于a(0),所以从f(1)开始判断
    int max = nums[0];
    dp[0] = max;
    for(int i = 1;i<numsSize;i++)
    {
        dp[i] = MAX(dp[i-1]+nums[i],nums[i]);
        max = MAX(dp[i],max);
    }
    return max;
}

int main()
{
    int nums[9] = {-2,1,-3,4,-1,2,1,-5,4};
    int len = sizeof(nums)/sizeof(int);
    printf("%d\n", dp_maxSubArray(nums,len));
}