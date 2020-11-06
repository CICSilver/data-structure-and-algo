/*
 * @Author: CICSilver
 * @Date: 2020-10-26 07:04:02
 * @Description: 反转字符串里的单词
 * @LastEditTime: 2020-10-26 07:31:15
 * @LastEditors: CICSilver
 * @FilePath: /ben/leetCode/_151_reverseWords.c
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char * reverseWords(char * s)
{
    int len = strlen(s);
    char* stack = (char *)malloc(len * sizeof(char));
    char* res = (char *)malloc(len * sizeof(char));
    int t = 0;
    int count = 0;
    int isWord = 0;
    //s中不止一个单词
    for(int i = len - 1;i>=0;--i)
    {
        if(s[i] !=' ')
        {
            stack[t++] = s[i];
            isWord = 1;
        }
        
        if(s[i] == ' ')
        {
            while(t > 0)
            {
                res[count++] = stack[--t];
            }
            if(isWord)
            {
                res[count++] = ' ';
                isWord = 0;
            }
        }
    }
    if(t == 0)
    {
        if(count > 0)
        {
            count --;
        }
    }
    while(t>0)
    {
        res[count++] = stack[--t];
    }
    res[count] = '\0';
    return res;
}

int main()
{
    char *s = "  hello world!  ";
    char * res = reverseWords(s);

}
