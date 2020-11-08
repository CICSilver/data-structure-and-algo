#ifndef _BINARY_TREE_H
#define _BINARY_TREE_H

typedef struct item
{
	int val;
}item;

typedef struct btree
{
	struct btree* left;
	struct item* data;
	struct btree* right;
}btree;

int tree_size;
btree* head;

item** stack1;
item** stack2;
int size_of_stack_one;
int size_of_stack_two;

void stack_one_init(int size);
void stack_two_init(int size);

void push_one(item*);
item* pop_one();

void push_two(item*);
item* pop_two();

void stack_init(int size);

btree* btree_init(int size);
int getVal(btree*);
btree* insert_btree_recursive(btree*, item*);
void insert_btree_nonrecursive(item*);
void prefix_recursive(btree*);
void infix_recursive(btree*);
void suffix_recursive(btree*);
void prefix_nonrecursive(btree*);
void infix_nonrecursive(btree*);
void suffix_nonrecursive(btree*);

btree* search_recursive(btree*, int);
btree* search_nonrecursive(btree*, int);

void destory(btree*);



#endif

