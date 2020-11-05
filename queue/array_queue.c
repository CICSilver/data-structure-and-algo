#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int QUEUE_SIZE = 0;
int real_size = 0;
int in_index = 0;
int out_index = 0;

int* queue_init(int len)
{
    int *queue = (int *)calloc(len,sizeof(int));
    QUEUE_SIZE = len;
    return queue;
}

void destory(int* queue)
{
    free(queue);
}

int push(int val, int* queue)
{
    if(real_size >= QUEUE_SIZE)
    {
        return NULL;
    }
    int temp_index = in_index % QUEUE_SIZE;
    queue[temp_index] = val;
    in_index++;
    real_size++;
    return 1;
}

int pop(int* queue)
{
    if(real_size<=0)
    {
        return NULL;
    }
    int temp_index = out_index%QUEUE_SIZE;
    out_index++;
    real_size--;
    return queue[temp_index];
}

int getSize()
{
    return QUEUE_SIZE;
}

int getitems()
{
    return real_size;
}

printAll(int* queue)
{
    for(int i = 0;i<real_size;i++)
    {
        printf("%d ", queue[(out_index+i)%QUEUE_SIZE]);
    }
    printf("\n");
}

int main()
{
    int len = 13;
    int* queue = queue_init(13);

    for(int i = 0;i<13;i++)
    {
        push(i,queue);
    }
    for(int i = 0;i<5;i++)
    {
        pop(queue);
    }
    push(100,queue);
    push(101,queue);
    push(102,queue);
    push(102,queue);
    push(102,queue);
    push(102,queue);
    push(102,queue);
    pop(queue);
    push(1020,queue);
    printAll(queue);
    printf("%d\n", getSize());
    printf("%d\n", getitems());
}