#include <stdio.h>
#include <stdlib.h>

typedef struct item
{
    int val
} item;

int STACK_SIZE = 0;

item **stack1;
int size_of_stack = 0;

int getItemVal(item* p_item)
{
    return p_item->val;
}

void show_item(item *p_item)
{
    printf("%d ", p_item->val);
}

item *item_new(int val)
{
    item *new_item = (item *)calloc(1, sizeof(item));
    new_item->val = val;
    return new_item;
}

int stack_init(int stack_size)
{
    if (stack_size <= 0)
    {
        return -1;
    }
    stack1 = (item **)calloc(stack_size, sizeof(item *));
    STACK_SIZE = stack_size;
    return 1;
}

int push(item *new_item)
{
    if (size_of_stack == STACK_SIZE)
    {
        return -1;
    }
    stack1[size_of_stack++] = new_item;
    show_item(new_item);
    return 1;
}

item *pop()
{
    return size_of_stack < 0 ? NULL : stack1[--size_of_stack];
}

int empty()
{
    return size_of_stack == 0;
}

int full()
{
    return size_of_stack == STACK_SIZE;
}

int get_size()
{
    return size_of_stack;
}

int main()
{
    stack_init(10);

    for (int i = 0; i < 10; ++i)
    {
        push(item_new(i));
    }
    printf("size = %d\n", get_size());
    for (int i = 0; i < 10; ++i)
    {
        printf("val = %d , size = %d\n",getItemVal(pop()), get_size());
    }
}