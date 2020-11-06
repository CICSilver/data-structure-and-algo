/*
 * @Author: CICSilver
 * @Date: 2020-10-20 06:09:48
 * @Description: 
 * @LastEditTime: 2020-10-20 08:37:51
 * @LastEditors: CICSilver
 * @FilePath: /ben/leetCode/_88_merge.c
 */
#include <stdio.h>
#include <string.h>

/**
 * @description: 
 * 给你两个有序整数数组 nums1 和 nums2，请你将 nums2 合并到 nums1 中，使 nums1 成为一个有序数组。
 * 
 *  说明：
 *  
 *  初始化 nums1 和 nums2 的元素数量分别为 m 和 n 。
 *  你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。
 *   
 *  
 *  示例：
 *  
 *  输入：
 *  nums1 = [1,2,3,0,0,0], m = 3
 *  nums2 = [2,5,6],       n = 3
 *  
 *  输出：[1,2,2,3,5,6]
 *   
 *  
 *  提示：
 *  
 *  -10^9 <= nums1[i], nums2[i] <= 10^9
 *  nums1.length == m + n
 *  nums2.length == n
 * 
 * nums1 = [1,2,3,3,3,3,3] m = 7 i = 0
 * nusm2 = [1,1,1,1,1,1,1] n = 7 j = 6 --
 * 
 * res[] = [1,1,1,1,1,1,1]
 */
void merge(int *nums1, int nums1Size, int m, int *nums2, int nums2Size, int n)
{
    if(n == 0)
    {
        return;
    }
    
    if(m == 0)
    {
        memcpy(nums1,nums2,sizeof(int) * n);
        return;
    }
    //m为nums1中元素数量，不是数组长度
    //n = nums2Size
    int temp_nums1[m];
    memcpy(temp_nums1, nums1, sizeof(int) * m);
    // int len_t = sizeof(temp_nums1)/sizeof(int);
    
    // printf("len_t = %d\n",len_t);

    int i = 0; //temp_nums1指针
    int j = 0; //nums2指针
    int t = 0; //结果数组nums1指针

    //取完标志
    int isNums1Done = 0;
    int isNums2Done = 0;

    int len = m + n;

    

    while (t < len)
    {
        //越界检查
        if (i >= m )
        {
            isNums1Done = 1;
        }
        if (j >= nums2Size)
        {
            isNums2Done = 1;
        }
        int remain = 0;
        if (isNums1Done)
        {
            remain = len - m - j;
            // if(remain>1)
            // {
            //     remain--;
            // }
            printf("remain = %d - %d - %d\n",len,m,j);
            for(int a = 0;a<remain;a++)
            {
                printf("remain = %d, t = %d, j = %d, nums2[j] = %d\n",remain,t+a,j+a,nums2[j+a]);
                nums1[t+a] = nums2[j+a];
            }
            break;
        }
        else if (isNums2Done)
        {
            remain = len - n - i;
            // if(remain>1)
            // {
            //     remain--;
            // }
            printf("remain = %d - %d - %d\n",len,n,i);
            for(int a = 0;a<remain;a++)
            {
                printf("remain = %d, t = %d, i = %d, nums1[i] = %d\n",remain,t+a,i+a,temp_nums1[i+a]);
                nums1[t+a] = temp_nums1[i+a];
            }
            break;
        }
        else
        {
            if (temp_nums1[i] < nums2[j])
            {
                printf("t = %d, i = %d\n",t,i);
                printf("adding nums1[i] = %d\n", temp_nums1[i]);
                nums1[t++] = temp_nums1[i++];
            }
            else
            {
                printf("t = %d, j = %d\n",t,j);
                printf("adding nums2[j] = %d\n", nums2[j]);
                nums1[t++] = nums2[j++];
            }
        }
    }

    for (int a = 0; a < len; a++)
    {
        printf("%d, ", nums1[a]);
    }
    printf("\n");
}

int main()
{
    int nums1[] = {1,2,4,5,6,0};
    int nums2[] = {3};

    merge(nums1, 6, 5, nums2, 1, 1);
}