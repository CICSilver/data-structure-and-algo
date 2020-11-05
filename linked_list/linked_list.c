#include "linked_list.h"

node* head = NULL;
node* tail = NULL;

node* node_new(item* new_item)
{
    node* new_node = (node *)calloc(1,sizeof(node));
    new_node->cur = new_item;
    new_node->prev = NULL;
    new_node->next = NULL;
    return new_node;
}

void add_at_head(node* new_node)
{
    insert_front(new_node, NULL);
}

void add_at_tail(node* new_node)
{
    insert_tail(new_node, NULL);
}
void insert_front(node* new_node, node* specefied_node)
{
    if(specefied_node == NULL)
    {
        //头插
        if (head != NULL)
        {
            new_node->next = head;
            head->prev = new_node;
        }else
        {
            tail = new_node;
        }
        head = new_node;
    }
    else
    {
        new_node->prev = specefied_node->prev;
        new_node->next = specefied_node;
        specefied_node->prev->next = new_node;
    }
}

void insert_tail(node* new_node, node* specefied_node)
{
    if(specefied_node == NULL)
    {
        //尾插
        if (head != NULL)
        {
            tail->next = new_node;
            new_node->prev = tail;
        }else
        {
            head = new_node;
        }
        tail = new_node;
    }
    else
    {
        new_node->next = specefied_node->next;
        new_node->prev = specefied_node;
        specefied_node->next->prev = new_node;        
    }
}

int get(int index)
{
    node* temp = head;
    while(index--)
    {
        temp = temp->next;
    }
    return get_val(temp);
}

int get_val(node* p_node)
{
    return p_node->cur->val;
}

int isExsist(int target)
{
    node* temp = head;
    while(temp)
    {
        if(get_val(temp) == target)
        {
            return 1;
        }
        temp = temp->next;
    }
    return -1;
}

node* del(node* p_node)
{
    if(!isExsist(get_val(p_node)))
    {
        return NULL;
    }
    p_node->next->prev = p_node->prev;
    p_node->prev->next = p_node->next;
    return p_node;
}