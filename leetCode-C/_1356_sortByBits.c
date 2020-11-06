#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *sortByBits(int *arr, int arrSize, int *returnSize)
{
    int *res = (int *)calloc(arrSize, sizeof(int));
    if (arr == NULL || arrSize == 0)
    {
        return NULL;
    }
    int begin, end;
    for (end = arrSize - 1; end >= 0; --end)
    {
        for (begin = 1; begin <= end; ++begin)
        {
            if (compare(arr[begin], arr[begin - 1]) < 0)
            {
                swap(&arr[begin], &arr[begin - 1]);
            }
        }
    }

    res = arr;
    *returnSize = arrSize;
    return arr;
}

//每次与操作会减少一位1
int count_bits(int a)
{
    int count = 0;
    while (a)
    {
        a &= (a - 1);
        count++;
    }
    return count;
}

int compare(int a, int b)
{
    if (a == b)
    {
        return 0;
    }

    int bit_a = count_bits(a);
    int bit_b = count_bits(b);

    if (bit_a == bit_b)
    {
        return compare_val(a, b);
    }

    return bit_a - bit_b;
}

int compare_val(int a, int b)
{
    return a - b;
}

void swap(int *a, int *b)
{
    if (a == b)
    {
        return;
    }

    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}
