/*
 * @Author: CICSilver
 * @Date: 2020-10-25 06:38:29
 * @Description: 解码方法 动态规划 0开头不可解码，铁憨批题目
 * 原题中0不可解码，本解法中0可解码，原题题意不清给爷爬
 * @LastEditTime: 2020-10-25 07:17:30
 * @LastEditors: CICSilver
 * @FilePath: /ben/leetCode/_91_numDecode.c
 */
#include <stdio.h>
#include <string.h>

//dp[i] = 1, i = 0
//dp[i] = dp[i-1] + 1, a[i-1] > 2 || a[i] > 6
//dp[i] = dp[i-1] + 2, a[i-1] <= 2 && a[i] <= 6

//当a[i] == 0时
//dp[i] = dp[i-1] + 1, a[i-1] <= 2 && a[i-1] >0
//dp[i] = dp[i-1],     a[i-1] == 0 || a[i-1] >2
int numDecodings(char * s)
{
    if(s == "" || s == NULL)
    {
        return 0;
    }
    int len = strlen(s);
    int dp[len];

    for(int i=0;i<len;i++)
    {
        dp[i] = getDP(s,dp,i);
    }
    return dp[len - 1];
}

int getDP(char* s, int* dp, int i)
{
    if(i == 0)
    {
        if(s[i] == '0')
        {
            return 0;
        }
        return 1;
    }
    
    if(s[i] == '0')
    {
        if(s[i-1]<='2' && s[i-1]>'0')
        {
            return dp[i-1]+1;
        }else
        {
            return dp[i-1];
        }
        
    }else
    {
        if(s[i-1]<=2 && s[i]<=6)
        {
            return dp[i-1]+2;
        }else
        {
            return dp[i-1]+1;
        }
        
    }
}

int main()
{
    char* s = "10";
    int res = numDecodings(s);
    printf("%d\n",res);
}