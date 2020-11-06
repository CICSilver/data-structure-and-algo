/*
 * @Author: CICSilver
 * @Date: 2020-10-24 06:05:35
 * @Description: 392 查找子串 动态规划解法
 * @LastEditTime: 2020-10-24 07:09:53
 * @LastEditors: CICSilver
 * @FilePath: /ben/leetCode/IMPORTANT___392_isSubsequence.c
 */
#include <stdio.h>
#include <string.h>

#define ENG_LEN 26

//dp[len+1][26] 相对位置表
//dp[i][j] = i, t[i] == (char)(j+97)
//dp[i][j] = dp[i+1][j], t[i] != (char)(j+97)
//dp[len][j] = len
int isSubsequence(char *s, char *t)
{
    int t_len = strlen(t);
    int s_len = strlen(s);
    int dp[t_len + 1][ENG_LEN];
    //初始化无匹配行
    for (int n = 0; n < ENG_LEN; ++n)
    {
        dp[t_len][n] = t_len;
    }
    //从后往前递推相对位置表
    for (int i = t_len - 1; i >= 0; --i)
    {
        for (int j = 0; j < ENG_LEN; ++j)
        {
            char cur_t = (char)(j + 97);
            if (t[i] == cur_t)
            {
                dp[i][j] = i;
            }else
            {
                dp[i][j] = dp[i + 1][j];
            }
        }
    }
    
    int num_of_s = 0;
    for(int i = 0;i<s_len;i++)
    {
        if(dp[num_of_s][s[i]-'a'] == t_len)
        {
            return 0;
        }
    }
    return 1;
}

//双指针
int isSubsequence2(char *s, char *t)
{
    while(*s && *t)
    {
        if(*s == *t)
        {
            s++;
        }
        t++;
    }
    return *s =='\0';
}


int main()
{
    char *s = "abc";
    char *t = "ahbgdc";
    isSubsequence(s, t);
}