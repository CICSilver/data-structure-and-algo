/*
 * @Author: CICSilver
 * @Date: 2020-10-28 13:50:18
 * @Description: 
 * @LastEditTime: 2020-10-28 17:37:39
 * @LastEditors: CICSilver
 * @FilePath: /ben/leetCode/_1207_uniqueOccurrences.c
 */
#include <stdio.h>
#include <string.h>
#define bool int
#define true 1
#define false 0

bool uniqueOccurrences(int* arr, int arrSize)
{
    int hash_len = 2001;
    //出现的次数
    int hash[hash_len];
    //出现的数
    int m[arrSize];

    // int hash2[arrSize];
    memset(hash,0,sizeof(hash));
    int count = 0;
    for(int i = 0;i<arrSize;++i)
    {
        if(hash[arr[i]+1000] == 0)
        {
            m[count++] = arr[i];
        }
        hash[arr[i]+1000]++;
    }

    // printf("\n");

    // for(int i = 0;i<count;++i)
    // {
    //     printf("m[%d] = %d, ",i, m[i]);
    // }
    // printf("\n");
    //出现次数的次数
    printf("count = %d\n",count);

    // int hash2[count];
    int t = 2;
    int hash2[t];
    
    for(int i = 0;i<count;++i)
    {
        int index = m[i] + 1000;
        // printf("1.%d\n",index);
    
        hash2[hash[index]]++;
        // if(hash2[hash[index]] > 1)
        // {
        //     return false;
        // }
        printf("m[%d] = %d\n",i,m[i]);
    }

    

    // printf("\n");

    // for(int i = 0;i<count;++i)
    // {
    //     printf("m[%d] = %d, ",i, m[i]);
    // }
    // printf("\n");
    return true;
}

int main()
{
    int arr[6] = {-1,-1,-1,-3,-1,-1};
    
    int res = uniqueOccurrences(arr,6);
    printf("\n%d\n", res);
}