#ifndef _BINARY_HEAP_H
#define _BINARY_HEAP_H

#include <stdio.h>
#include <stdlib.h>

typedef struct item
{
    int val;
}item;

int head_size;

item** heap;

int heap_size;

int CAPACITY;

item* get_item_from_heap(int index);

item** heap_init(int size);

item* item_new(int val);

//返回堆容量
int capacity();

//返回堆大小
int size();

//堆是否为空
int isEmpty();

//返回指定索引的父索引
int get_parent(int index);

//返回指定索引的左子结点索引
int get_leftChild(int index);

//返回指定索引的右子节点索引
int get_rightChild(int index);

//插入新item
void add(item* new_item);

//堆化插入后的新堆，新插入目标上浮
void sift_up(item**, int index);

void sift_down(item**, int index, int size);

//查看堆中的最大值
item* peekMax();

//弹出堆中的最大值
item* popMax();

//取出最大元素并替换成新插入的
item* replace(item* new_item);

//堆化一个元素数组
item** heapify(item** arr, int arrSize);

void swap(item* a, item* b);

//将heap1拷贝到heap2，动态扩容的辅助方法
void heapCopy(item** heap1, item** heap2);

void printAll();


#endif