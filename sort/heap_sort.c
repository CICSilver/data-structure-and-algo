#include "../heap/max_binary_heap_with_array.h"

#define LEN 10
item** getArr(item** arr,int arrSize)
{
    int nums[] = {5,1,3,12,0,8,7,15,9,6};
    for(int i = 0;i<arrSize;++i)
    {
        arr[i] = item_new(nums[i]);
    }
    return arr;
}

//堆排序，思路：
//因为使用的是最大堆，所以arr[0]必然为当前堆中的最大元素
//每次将arr[0]和arr[size - count]交换，则[arrSize - count,arrSize - 1]区间即已完成排序部分
//再把[0,arrSize - count)堆化，继续重复上述过程，即可完成排序
item** heap_sort(item** arr, int arrSize)
{
    // printf("1\n");
    arr = heapify(arr, arrSize);
    for(int i = 1;i <arrSize; i++)
    {
        swap(arr[0], arr[arrSize - i]);
        heapify(arr, arrSize - i);
    }
    return arr;
}

void showAll(item** heap)
{
    for (int i = 0; i < LEN; i++)
    {
        printf("%d ", heap[i]->val);
    }
    printf("\n");
}

int main()
{
    item** arr = heap_init(LEN);
    arr = getArr(arr, LEN);
    // showAll(arr);
    arr = heap_sort(arr, LEN);
    showAll(arr);
}