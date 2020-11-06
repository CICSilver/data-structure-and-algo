/*
 * @Author: CICSilver
 * @Date: 2020-10-21 12:30:09
 * @Description: 面试题01.06 压缩字符串
 * @LastEditTime: 2020-10-21 12:57:07
 * @LastEditors: CICSilver
 * @FilePath: /ben/leetCode/_M0106_compressString.c
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *compressString(char *S)
{
    if (S == NULL)
    {
        return S;
    }
    int oldLen = strlen(S);
    char str[oldLen];
    char buffer[10];
    printf("oldLen = %d\n", oldLen);
    int flag = 0;

    for (int i = 0; i < oldLen; i++)
    {

        while (i < oldLen)
        {
            int j = i;
            int count = 0;
            // printf("44\n");
            char *temp = S[i];
            // printf("33\n");
            strcat(str, &temp);
            // printf("11\n");
            if (isLongger(str, oldLen))
            {
                flag = 1;
                break;
            }
            char *count_c;
            // printf("22\n");
            while (S[j++] == S[i])
            {
                ++count;
            }
            i = j - 1;
            sprintf(buffer, "%d", count);
            strcat(str, buffer);
            printf("str = %s\n", str);
            if (isLongger(str, oldLen))
            {
                flag = 1;
                break;
            }
        }
    }
    if (!flag)
    {
        int newLen = strlen(str);
        strcpy(S,str);
        
        printf("str in func = %s\n",S);
    }
    return S;
}

int isLongger(char *str, int oldLen)
{
    return (strlen(str) == oldLen);
}

int main()
{
    char *S = "aabcccccaa";
    char *str = compressString(S);
    printf("%s\n", S);
    return 0;
}