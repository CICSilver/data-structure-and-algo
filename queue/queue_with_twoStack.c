#include <stdlib.h>
#include <stdio.h>

/**
 * 两个栈实现的队列，思路如下
 * 栈的FILO规则导致一次dump会颠倒顺序，所以两个栈一进一出即可完成队列。
 * 一个队列用于接受enqueue的item，每次调用dqueue时会将所有一号栈的item倒入二号栈
 * 由二号栈进行dequeue操作。会引起空间浪费。
 * 进队时考虑一号栈是否已满，若一号栈已满且二号栈为空则全部倒入二号栈，否则拒绝操作。
 * 出队时考虑二号栈是否为空，若二号为空则将一号栈倒入二号栈。
 */

typedef struct item
{
    int val
}item;

int STACK_SIZE = 0;

item **stack1;
int size_of_stack_one = 0;
item **stack2;
int size_of_stack_two = 0;

void show_item(item* p_item)
{
    printf("%d ", p_item->val);
}

item* item_new(int val)
{
    item* new_item = (item*)calloc(1,sizeof(item));
    new_item->val = val;
    return new_item;
}

int stack_init(int stack_size)
{
    if(stack_size <= 0)
    {
        return -1;
    }
    stack1 = (item **)calloc(stack_size, sizeof(item *));
    stack2 = (item **)calloc(stack_size, sizeof(item *));
    STACK_SIZE = stack_size;
    return 1;
}

int push_one(item* new_item)
{
    if(size_of_stack_one == STACK_SIZE)
    {
        return -1;
    }
    stack1[size_of_stack_one++] = new_item;
    return 1;
}

item* pop_one()
{
    return size_of_stack_one<0? NULL:stack1[--size_of_stack_one];
}

int empty_one()
{
    return size_of_stack_one == 0;
}

int full_one()
{
    return size_of_stack_one == STACK_SIZE;
}

int push_two(item* new_item)
{
    if(size_of_stack_two == STACK_SIZE)
    {
        return -1;
    }
    stack1[size_of_stack_two++] = new_item;
    return 1;
}

item* pop_two()
{
    return size_of_stack_two<0? NULL:stack1[--size_of_stack_two];
}

int empty_two()
{
    return size_of_stack_two == 0;
}

int full_two()
{
    return size_of_stack_two == STACK_SIZE;
}

void queue_init(int size)
{
    stack_init(size);
}

int full_queue()
{
    return full_one() && full_two();
}

int empty_queue()
{
    return empty_one() && empty_two();
}

void enqueue(int val)
{
    if(full_queue)
    {
        printf("queue is full!\n");
        return;
    }
    if(!full_one)
    {
        push_one(item_new(val));
    }else
    {
        while(!empty_one() && !full_two())
        {
            push_two(pop_one);
        }
        push_one(item_new(val));
    }
}

//考虑第二个栈的item顺序， 仅当第二个栈空时，才能将第一个栈dump过来
//可能存在空间浪费，即当第二个栈非空且第一个栈爆栈时，整个队列大小仅为第一个栈的总大小
//加上第二个栈的当前存储个数，第二个栈的剩余空间无法有效利用
item* dequeue()
{
    int res;
    if(empty_queue())
    {
        return NULL;
    }
    if(empty_two())
    {
        while(!empty_one() && !full_two())
        {
            push_two(pop_one());
        }
    }
    res = pop_two();
    return res;
}

int get_queue_size()
{
    return (size_of_stack_one+size_of_stack_two);
}
