#include <stdio.h>
#include <stdlib.h>


typedef struct item_int{
    int val;
}item;

typedef struct Node{
    node* prev;
    item* cur;
    node* next; 
}node;

node* node_new(item* new_item);

void add_at_head(node* new_node);
void add_at_tail(node* new_node);

void insert_front(node* new_node, node* specefied_node);

void insert_tail(node* new_node, node* specefied_node);

int get(int index);

int get_val(node*);

int isExsist(int target);

node* del(node*);