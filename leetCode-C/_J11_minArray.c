#include <stdio.h>
#include <stdlib.h>

//边界处理，结果可能出现于两个区间与其边界，该二分查找无法找到边界情况，
int minArray(int* numbers, int numbersSize)
{
    if(numbers == NULL || numbersSize == 0)
    {
        return 0;
    }
    if(numbersSize == 1)
    {
        return numbers[0];
    }
    // printf("1\n");
    int left = 0;
    int right = numbersSize - 1;
    int res;
    int isRes = 0;
    //未旋转的完全排序数组
    if(numbers[right] > numbers[left])
    {
        return numbers[0];
    }
    // //只有一个元素的数组
    // if(numbers[right] == numbers[left])
    // {
    //     return numbers[0];
    // }


    while(left <= right)
    {
        // printf("1\n");
        int mid = (left+right)/2;
        // printf("%d\n", mid);
        if(mid > 0 && numbers[mid] < numbers[mid - 1])
        {
            printf("1\n");
            res = numbers[mid];
            isRes = 1;
            break;
        }
        if(mid < numbersSize - 1 && numbers[mid] > numbers[mid + 1])
        {
            printf("2\n");
            res = numbers[mid + 1];
            isRes = 1;
            break;
        }
        if(numbers[mid] < numbers[right])
        {
            right = mid - 1;
        }else
        if(numbers[mid] > numbers[left])
        {
            left = mid + 1;
        }else
        {
            left++;
            right--;
        }
    }
    if(!isRes)
    {
        res = numbers[0];
    }
    
    return res;
}

int main()
{
    int nums[] = {3,1,3};
    int res = minArray(nums, 3);
    printf("%d\n", res);
    return 0;
}