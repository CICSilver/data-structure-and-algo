#include "max_binary_heap_with_array.h"

item* item_new(int val)
{
    item* new_item = (item *)calloc(1,sizeof(item));
    new_item->val = val;
    return new_item;
}

int get_val_from_item(item* p_item)
{
    return p_item->val;
}

item* get_item_from_heap(int index)
{
    if(index>=0 && index <capacity)
    {
        return heap[index];
    }
    printf("访问越界!\n");
    return NULL;
}

void heap_init(int size)
{
    heap = (item *)calloc(size,sizeof(item));
    CAPACITY = size;
    heap_size = 0;
}

//返回堆大小
int size()
{
    return heap_size+1;
}

//返回堆容量
int capacity()
{
    return CAPACITY;
}

//堆是否为空
int isEmpty()
{
    return heap_size == 0;
}

int isFull()
{
    return heap_size == CAPACITY;
}

//返回指定索引的父索引
int get_parent(int index)
{
    return index/2;
}

//返回指定索引的左子结点索引
int get_leftChild(int index)
{
    return index*2;
}

//返回指定索引的右子节点索引
int get_rightChild(int index)
{
    return index*2+1;
}

//插入新item
void add(item* new_item)
{
    if(isFull())
    {
        printf("元素已满!\n");
        return;
    }
    heap[heap_size++] = new_item;
    int cur = size()-1;
    sift_up(cur);
}

//堆化插入后的新堆，新插入目标上浮
//思路：重复和父结点比较，小于父结点则和父结点交换，大于父结点即已完成
void sift_up(int index)
{
    while(index>0 && get_val_from_item(get_item_from_heap(index)) < get_val_from_item(get_item_from_heap(get_parent(index))))
    {
        swap(heap[index], get_item_from_heap(get_parent(index)));
        //todo 1105
    }
}

void sift_down(int index);

//查看堆中的最大值
item* peekMax();

//弹出堆中的最大值
item* popMax();

//取出最大元素并替换成新插入的
item* replace(item* new_item);

//堆化一个元素数组
void headpiy(item** arr);

void swap(item* a, item* b);
