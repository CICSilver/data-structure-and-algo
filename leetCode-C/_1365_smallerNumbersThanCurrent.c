/*
 * @Author: CICSilver
 * @Date: 2020-10-26 06:12:59
 * @Description: 第1365题 有多少小于当前数字的数字
 * @LastEditTime: 2020-10-26 06:56:56
 * @LastEditors: CICSilver
 * @FilePath: /ben/leetCode/_1365_smallerNumbersThanCurrent.c
 */

#include <stdio.h>
#include <stdlib.h>

int* smallerNumbersThanCurrent(int *nums, int numsSize, int *returnSize)
{
    int *res = (int *)malloc(numsSize * sizeof(int));
    int dp[101] = {0};
    int count = 0;
    for (int i = 0; i < numsSize; ++i)
    {
        dp[nums[i]]++;
        if (dp[nums[i]] == 1)
        {
            count++;
        }
    }
    // for(int i = 0;i<101;i++)
    // {
    //     printf("%d, ",dp[i]);
    // }
    printf("count = %d\n", count);
    int i = 0;
    int sum = 0;
    int pre_sum = 0;
    while (count > 0)
    {
        if (dp[i] != 0)
        {
            sum+=dp[i];
            dp[i] = pre_sum;
            pre_sum = sum;
            count--;
            printf("dp[%d] = %d, sum = %d\n", i, dp[i],sum);
        }
        i++;
    }
    for(int j = 0;j<numsSize;++j)
    {
        res[j] = dp[nums[j]];
    }
    return res;
}

int main()
{
    int nums[5] = {8, 1, 2, 2, 3};
    int *res = smallerNumbersThanCurrent(nums, 5, 5);
    for(int i = 0;i<5;i++)
    {
        printf("%d, ",res[i]);
    }
    printf("end\n");
    free(res);
}
