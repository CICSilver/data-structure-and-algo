#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

#define INIT_SIZE 10

int* stack;
int capacity;
int stack_size;

void stack_init(int size)
{
    stack = (int *)calloc(size, sizeof(int));
    capacity = size;
    stack_size = 0;
}

void push(int item)
{
    ensure_expan();
    stack[stack_size++] = item;
}

int ensure_expan()
{
    int minCapacity = stack_size + 1;
    if(minCapacity - capacity > 0)
    {
        grow(minCapacity);
    }
}

void grow(int minCapacity)
{
    int oldCapacity = capacity;
    int newCapacity = oldCapacity + (oldCapacity >> 1);
    if(minCapacity <= 1)
    {
        newCapacity = 10;
    }
    if(newCapacity - minCapacity < 0)
    {
        newCapacity = minCapacity;
    }

    printf("cur stack size:%d\n",stack_size);
    printf("new stack size:%d\n",newCapacity);
    stack = (int *)realloc(stack, newCapacity*sizeof(int));
    capacity = newCapacity;
    printf("stack_capacity after realloc:%d\n", capacity);
}


int main()
{
    stack_init(INIT_SIZE);
    printf("stack size after init:%d\n", capacity);

    int len = 100;
    for(int i = 0;i<len;i++)
    {
        push(i);
    }
    for(int i = 0;i<len;i++)
    {
        printf("%d ", stack[i]);
    }
    printf("\n");
}