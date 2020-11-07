#include "max_binary_heap_with_array.h"

#define LEN 10

void setAll()
{
    for (int i = 0; i < LEN; i++)
    {
        heap[i] = item_new(i);
    }
}

void showAll()
{
    for (int i = 0; i < LEN; i++)
    {
        printf("%d ", heap[i]->val);
    }
    printf("\n");
}
/**
 *                  8(0)                           
 *              6(1)        7(2)
 *           5(3)    3    2    1 
 *         4(7)  0(8)  
 */

int main()
{
    heap_init(LEN);
    for(int i = 0;i<10;i++)
    {
        heap[i] = item_new(i);
    }
    // showAll();
    heap_size = LEN;
    printAll();

    heapify(heap, LEN);
    printAll();
}