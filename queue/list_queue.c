#include <stdlib.h>
#include <stdio.h>

typedef struct item
{
    int val;
}item;

typedef struct node 
{
    item* cur;
    node* next;
}node;

node* head = NULL;
node* tail = NULL;

item* item_new(int val)
{
    item* new_item = (item *)calloc(1, sizeof(item));
    new_item->val = val;
    return new_item;
}

node* node_new(item* new_item)
{
    node* new_node = (node *)calloc(1, sizeof(node));
    new_node->cur = new_item;
    return new_node;
}

void push(node* new_node)
{
    if(tail == NULL)
    {
        new_node->next = NULL;
        tail = new_node;
        head = new_node;
    }else
    {
        tail->next = new_node;
        new_node->next = NULL;
        tail = new_node;
    }
}

node* pop()
{
    if(head == NULL)
    {
        return NULL;
    }
    node* res = head;
    head = head->next;
    res->next = NULL;

    return res;
}

